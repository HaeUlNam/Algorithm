#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct info{
    int y, x;
    int dis;
};

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int map[17][17];
vector<int> gun;

int N, M, D;

int Max = INT_MIN;

int calculate()
{
    int result = 0;
    int ccpy_map[17][17];
    int cpy_map[17][17];

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cpy_map[i][j] = map[i][j];
        }
    }

    while(1)
    {
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                ccpy_map[i][j] = cpy_map[i][j];
            }
        }

        //3개 궁수 사거리 내에 일제 사격
        for(int i = 0; i < 3; i++)
        {
            int visit[17][17] = {0};

            info aa = {N, gun[i], 0};

            queue<info> q;
            q.push(aa);
            visit[aa.y][aa.x] = 1;

            while(!q.empty())
            {
                info a = q.front();
                q.pop();

                //end condition
                if(a.dis > D) break;

                if(cpy_map[a.y][a.x] == 1)
                {
                    int localdis = a.dis;
                    while(!q.empty())
                    {
                        info d = q.front();
                        q.pop();
                        
                        if(localdis < d.dis) break; 

                        if(cpy_map[d.y][d.x] == 1 && d.x < a.x)
                        {
                            a.x = d.x; a.y = d.y; a.dis = d.dis;
                        }
                    }
                    ccpy_map[a.y][a.x] -= 2;
                    break;
                }
                
                for(int i = 0; i < 4; i++)
                {
                    int nr = a.y + dr[i];
                    int nc = a.x + dc[i];

                    if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) continue;
                    if(visit[nr][nc]) continue;
                    if(cpy_map[nr][nc] == 2) continue;

                    visit[nr][nc] = 1;
                    info cc = {nr, nc, a.dis + 1};
                    q.push(cc);
                }
            }
        }

        bool check = true;
        
        //사격 후에 0보다 작은 것 체크
        for(int y = 0; y < N; y++)
        {
            for(int x = 0; x < M; x++)
            {
                if(ccpy_map[y][x] == 1) check = false;

                if(ccpy_map[y][x] < 0)
                {
                    result++;
                    cpy_map[y][x] = 0;
                }
                else
                {
                    cpy_map[y][x] = ccpy_map[y][x];
                }
            }
        }

        if(check) break;

        //맨 아래 초기화 후 한칸 내리기
        for(int i = 0; i < M; i++)
            cpy_map[N-1][i] = 0;

        for(int y = N - 2; y >= 0; y--)
        {
            for(int x = M - 1; x >= 0; x--)
            {
                cpy_map[y + 1][x] = cpy_map[y][x];
                cpy_map[y][x] = 0;
            }
        }
    }

    return result;
}

void solve()
{
    for(int i = 0; i < M; i++)
    {
        gun.push_back(i);
        for(int j = i + 1; j < M; j++)
        {
            gun.push_back(j);
            for(int k = j + 1; k < M; k++)
            {
                gun.push_back(k);
                Max = max(Max, calculate());
                gun.pop_back();
            }   
            gun.pop_back();
        }
        gun.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> D;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> map[y][x];
        }
    }

    for(int i = 0; i < M; i++)
        map[N][i] = 2;

    solve();

    cout << Max << "\n";

    return 0;
}