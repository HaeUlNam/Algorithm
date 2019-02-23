#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct info{
    int x,y, num;
};

int map[105][105];
int N;

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int Min = INT_MAX;

void changeColor()
{
    int count = 2;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 1)
            {
                queue<info> q;
                q.push({i,j});
                map[i][j] = count;

                while(!q.empty())
                {
                    info aa = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int nr = aa.x + dr[k];
                        int nc = aa.y + dc[k];

                        if(!(0<= nr && nr < N && 0 <= nc && nc < N)) continue;
                        if(map[nr][nc] == 0 || map[nr][nc] == count) continue;

                        map[nr][nc] = count;
                        q.push({nr,nc});
                    }
                }

                count++;
            }
        }
    }

}

void getShortest()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] != 0)
            {
                int visit[105][105] = {0};

                int localCount = map[i][j];
                queue<info> q;
                visit[i][j] = 1;
                q.push({i,j,0});

                bool gg = false;

                while(!q.empty())
                {
                    info aa = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int nr = aa.x + dr[k];
                        int nc = aa.y + dc[k];

                        if(!(0<= nr && nr < N && 0<= nc && nc < N)) continue;
                        if(visit[nr][nc] == 1) continue;
                        if(map[nr][nc] == localCount) continue;

                        if(map[nr][nc] != localCount && map[nr][nc] != 0)
                        {
                            Min = min(aa.num, Min);
                            gg = true;
                            break;
                        }

                        visit[nr][nc] = 1;
                        q.push({nr,nc,aa.num + 1});   
                    }

                    if(gg) break;
                }

            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    changeColor();

    getShortest();

    cout << Min << endl;

    return 0;
}