#include<iostream>
#include<queue>
using namespace std;

struct info{
    int x, y;
};

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int w, h;
char map[1005][1005];
int visit[1005][1005];

queue<info> fire;
queue<info> sang;

int result;

bool bfs()
{
    int localCount = 1;

    while(!sang.empty())
    {
        int fsize = fire.size();

        //불이 퍼지도록
        for(int j = 0; j < fsize; j++)
        {
            info a = fire.front();
            fire.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = a.x + dr[i];
                int nc = a.y + dc[i];

                if(!(0 <= nr && nr < h && 0 <= nc && nc < w)) continue;
                if(map[nr][nc] == '#' || map[nr][nc] == '*') continue;

                map[nr][nc] = '*';
                fire.push({nr,nc});
            } 
        }

        int ssize = sang.size();

        //상근이 퍼지는 것
        for(int j = 0; j < ssize; j++)
        {
            info a = sang.front();
            sang.pop();

            if(a.x == 0 || a.x == h-1 || a.y == 0 || a.y == w-1)
            {
                result = localCount;
                return true;
            }

            for(int i = 0; i < 4; i++)
            {
                int nr = a.x + dr[i];
                int nc = a.y + dc[i];

                if(!(0 <= nr && nr < h && 0 <= nc && nc < w)) continue;
                if(map[nr][nc] == '#' || map[nr][nc] == '*') continue;
                if(visit[nr][nc] == 1) continue;
                if(nr == 0 || nr == h-1 || nc == 0 || nc == w-1)
                {
                    result = localCount + 1;
                    return true;
                }

                visit[nr][nc] = 1;
                sang.push({nr,nc});
            } 
        }
        localCount++;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for(int x = 0; x < testcase; x++)
    {
        cin >> w >> h;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '*') fire.push({i,j});
                else if(map[i][j] == '@')
                {   
                    sang.push({i,j});
                    visit[i][j] = 1;
                } 
            }
        }   

        if(bfs()) cout << result << '\n';
        else cout << "IMPOSSIBLE" << '\n';

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                visit[i][j] = 0;
            }
        }

        while(!fire.empty()) fire.pop();
        while(!sang.empty()) sang.pop(); 
    }

    return 0;
}

/*
배운 점 : map을 가장 작게 만들었을 때, 커버하는지 체크해야한다.
        visit함수는 항상 쓸 수 있는지 고민.
*/