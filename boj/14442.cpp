#include<iostream>
#include<queue>
using namespace std;

struct info{
    int y, x, crush;
    int path;
};

//동,남,서,북
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int N, M, K;
int map[1005][1005];
int visit[1005][1005][11];

int result = -1;

/* BFS의 가장 중요한 점은 언제 최단일 것인가? 하는 거다. 바로 break 걸어야 하는지, 같은 시간동안 체크해야하는지.. */
void bfs()
{
    queue<info> q;
    info z; z.y = 1; z.x = 1; z.path = 1; z.crush = 0;
    q.push(z);

    while(!q.empty())
    {   
        info a = q.front();
        q.pop();

        if(a.y == N && a.x == M)
        {
            result = a.path;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = a.y + dy[i];
            int nc = a.x + dx[i];
            int crush = a.crush;

            if(!(0 < nr && nr <= N && 0 < nc && nc <= M)) continue;
            if(map[nr][nc])
            {
                if(crush >= K) continue;
                else
                    crush++;
            }
            if(visit[nr][nc][crush]) continue;

            visit[nr][nc][crush] = 1;
            info b;
            b.y = nr; b.x = nc; b.crush = crush; b.path = a.path + 1;
            q.push(b);
        }
    }
}

int main()
{
    cin >> N >> M >> K;

    char input[1005];
    for(int y = 1; y <= N; y++)
    {
        cin >> input;
        for(int x = 1; x <= M; x++)
        {
            map[y][x] = input[x - 1] - '0';
        }
    }

    bfs();

    cout << result << endl;

    return 0;
}

/*
실수한 점 : 방향을 바꾸면서 다음 칸으로 갈 때, Crush 같은 건 변수를 따로 분리해서 현재에서만 영향을 미치도록 하여야 한다.

어려웠던 점 : 벽을 부수는 개수에 따라 visit을 다르게 둔다는 것이 이해가 되지 않았는데, 1번만 부술 수 있을 때를 가정으로 생각하니 괜찮았다.

만약, 한번 부수고 간 경로가 특정 위치에 먼저 도착했을 때 이차원 visit으로 체크하면, 또 한번 더 부수고 목적지를 찾아야만 할 때 찾지 못한다.

*/