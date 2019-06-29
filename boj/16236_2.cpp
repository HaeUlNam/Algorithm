#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

struct info{
    int y,x;
    int size, count;
    int tt;
};

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

info Start;
int N;

int map[21][21];

bool solve()
{
    bool localCheck = false;
    int visit[21][21] = {0};

    queue<info> q;
    q.push(Start);
    visit[Start.y][Start.x] = 1;

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        cout << a.y << " / " << a.x << "\n";

        if(1 <= map[a.y][a.x] && map[a.y][a.x] <= 6 && a.size > map[a.y][a.x])
        {
            localCheck = true;
            int yy = a.y, xx = a.x;
            int localtt = a.tt;

            while(!q.empty())
            {
                info b = q.front();
                q.pop();
                if(b.tt > localtt) break;

                if(map[b.y][b.x] && b.size > map[b.y][b.x])
                {
                    if(b.y < yy || (b.y == yy && b.x < a.x))
                    {
                        yy = b.y; xx = b.x;
                    }
                }
            }

            map[yy][xx] = 0;
            Start.y = yy; Start.x = xx;
            Start.tt = localtt;
            Start.count++;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = a.y + dr[i];
            int nc = a.x + dc[i];

            if(!(0 <= nr && nr < N && 0 <= nc && nc < N)) continue;
            if(map[nr][nc] > a.size) continue;
            if(visit[nr][nc]) continue;

            info cc = {nr, nc, a.size, a.count, a.tt + 1};
            visit[nr][nc] = 1;
            q.push(cc);
        }
    }

    return localCheck;
}

int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // freopen("debug.txt","w",stderr);
    
    cin >> N;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> map[y][x];
            if(map[y][x] == 9)
            {
                Start.y = y; Start.x = x; Start.count = 0;
                Start.size = 2; Start.tt = 0; map[y][x] = 0;
            }
        }
    }

    bool check = true;
    while(check)
    {
        check = solve();
        if(Start.size == Start.count)
        {
            Start.size++;
            Start.count = 0;
        }
    }

    cout << Start.tt << "\n";

    return 0;
}