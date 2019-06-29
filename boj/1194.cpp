#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct info{
    int y, x;
    int count;
    int key[6];    
};

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int N, M;
char map[55][55];
int visit[55][55][2][2][2][2][2][2];

info start;
int result = -1;

void bfs()
{
    queue<info> q;
    q.push(start);

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        //End condition
        if(map[a.y][a.x] == '1')
        {
            result = a.count;
            break;
        }

        if('a' <= map[a.y][a.x] && map[a.y][a.x] <= 'f')
        {
            int idx = map[a.y][a.x] - 'a';
            a.key[idx] = 1;
        }

        //exception
        if('A' <= map[a.y][a.x] && map[a.y][a.x] <= 'F')
        {
            int idx = map[a.y][a.x] - 'A';
            if(!a.key[idx]) continue;
        }

        int k0 = a.key[0], k1 = a.key[1], k2 = a.key[2], k3 = a.key[3], k4 = a.key[4], k5 = a.key[5];

        for(int i = 0; i < 4; i++)
        {
            int nr = a.y + dy[i];
            int nc = a.x + dx[i];

            if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) continue;
            if(map[nr][nc] == '#') continue;
            if(visit[nr][nc][k0][k1][k2][k3][k4][k5]) continue;

            visit[nr][nc][k0][k1][k2][k3][k4][k5] = 1;
            info bb = a;
            bb.y = nr; bb.x = nc;
            bb.count++;

            q.push(bb);
        }
    }
}

int main()  
{   
    cin >> N >> M;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> map[y][x];
            if(map[y][x] == '0')
            {
                start.y = y; start.x = x; start.count = 0;
                for(int k = 0; k < 6; k++)
                    start.key[k] = 0;
            }
        }
    }

    bfs();

    cout << result << '\n';

    return 0;
}
/*
실수한 부분 : #일 때 continue 처리를 안해줬다.

* 어려웠던 부분

- 열쇠를 먹을 때마다 visit을 다르게 해주어야 했기에, visit을 8차원으로 하도록 하는 것이 어려웠다.
- BFS에서 queue push 이전에 해야 할 것이 있고, queue push 이후에 해야 할 예외처리들이 있는데 이를 잘 구분하도록 하자.
    - push 이전 예외처리 : 값을 바꾸지 않고, 단순 비교하는 것들
    - push 이후 예외처리 : end condition, 값을 바꾸고 비교하는 것.
*/