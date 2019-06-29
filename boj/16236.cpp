#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;
#define MAX_ROW 25
#define MAX_COL 25

//동, 남, 서, 북
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

struct info{
    int y, x;
    int eat, size;
    int time;
};

int N;

int map[MAX_ROW][MAX_COL];
int visit[MAX_ROW][MAX_COL];

int result;                     //결과 출력

void bfs(info start)
{
    queue<info> q;
    q.push(start);
    visit[start.y][start.x] = 1;

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        //End condition
        if(map[a.y][a.x]!= 0 && map[a.y][a.x] < a.size)
        {
            result = a.time;

            //반복문 돌면서, 큐에 들어 있는 같은 시간인 것들 체크..
            while(!q.empty())
            {
                info b = q.front();
                q.pop();
                
                if(b.time > result) break;
                if(map[b.y][b.x] == 0 || map[b.y][b.x] >= a.size) continue;

                if(b.y < a.y || ((b.y == a.y) && (b.x < a.x)))
                {
                    a = b;
                }
            }

            //물고기 먹으면 빈칸
            map[a.y][a.x] = 0;
            
            a.eat++;
            //먹은 개수가 자신의 크기와 동일하면, 먹은 개수 초기화 & 크기 1 증가.
            if(a.eat == a.size)
            {
                a.eat = 0;
                a.size++;
            }

            //visit 초기화 & queue clear하고 현재 지점만 push
            for(int y = 1; y <= N; y++)
            {
                for(int x = 1; x <= N; x++)
                {
                    visit[y][x] = 0;
                }
            }

            while(!q.empty()) q.pop(); 

            q.push(a);
            visit[a.y][a.x] = 1;
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = dy[i] + a.y;
            int nc = dx[i] + a.x;

            //Exception Handling
            if(!(0 < nr && nr <= N && 0 < nc && nc <= N)) continue;
            if(visit[nr][nc]) continue;
            if(map[nr][nc] > a.size) continue;
            
            visit[nr][nc] = 1;
            info aa;
            aa.y = nr; aa.x = nc; aa.eat = a.eat; aa.size = a.size; aa.time = a.time + 1;
            q.push(aa);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    info start;

    cin >> N;

    //input
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> map[y][x];
            if(map[y][x] == 9)
            {
                map[y][x] = 0;
                start.y = y; start.x = x;
                start.eat = 0; start.size = 2;
                start.time = 0;
            }
        }
    }

    //start 지점의 좌표를 지정.
    bfs(start);

    cout << result << endl;

    return 0;
}
