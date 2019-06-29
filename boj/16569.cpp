#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

struct info{
    int y, x, T;
};  

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

queue<info> jesang;
queue<info> fire;

vector<info> vec;

int map[105][105];
int visit[105][105];

int M, N, V;
int X, Y;

int resultHigh = -1, resultTime = 0;

int GG(info a, info b)
{
    return a.T < b.T;
}

void solve()
{
    int begiFire = 0;
    int tcount = 0;

    info aaa;
    aaa.y = X; aaa.x = Y; aaa.T = 0;

    jesang.push(aaa);
    visit[X][Y] = 1;

    while(!jesang.empty())
    {
        //올바른 불을 넣기
        while(begiFire < vec.size())
        {
            info c = vec[begiFire];

            if(c.T != tcount) break;
            
            fire.push(c);
            begiFire++;
        }

        //불 시간동안 돌리기
        while(!fire.empty())
        {
            info d = fire.front();
            if(tcount < d.T) break;
            fire.pop();
            map[d.y][d.x] = -1;

            for(int i = 0; i < 4; i++)
            {
                int nr = d.y + dy[i];
                int nc = d.x + dx[i];

                if(!(0 < nr && nr <= M && 0 < nc && nc <= N)) continue;
                if(map[nr][nc] == -1) continue;

                info b;
                b.y = nr; b.x = nc; b.T = d.T + 1;

                fire.push(b);
            }
        }

        //재상이 이동
        while(!jesang.empty())
        {
            info a = jesang.front();
            if(tcount < a.T) break;
            jesang.pop();

            if(resultHigh < map[a.y][a.x])  
            {
                resultHigh = map[a.y][a.x];
                resultTime = a.T;
            }

            for(int i = 0; i < 4; i++)
            {
                int nr = a.y + dy[i];
                int nc = a.x + dx[i];

                if(!(0 < nr && nr <= M && 0 < nc && nc <= N)) continue;
                if(visit[nr][nc]) continue;
                if(map[nr][nc] < 0) continue;

                info b;
                b.y = nr; b.x = nc; b.T = a.T + 1;

                jesang.push(b);
                visit[nr][nc] = 1;
            }
        }

        tcount++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> M >> N >> V;
    cin >> X >> Y;

    for(int y = 1; y <= M; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> map[y][x];
        }
    }

    for(int i = 0; i < V; i++)
    {
        info aa;
        cin >> aa.y >> aa.x >> aa.T;
        vec.push_back(aa);
        //key point!!!!!    
        map[aa.y][aa.x] = -100;
    }

    sort(vec.begin(), vec.end(), GG);

    solve();

    cout << resultHigh << " " <<  resultTime << "\n";

    return 0;
}