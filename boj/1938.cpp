#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdlib>
#include<queue>
using namespace std;

struct info{
    int y[3], x[3];
    int count;
    int dir;
};

int dr[][3] = {
    {-1,-1,-1},
    {1,1,1},
    {0,0,0},
    {0,0,0},
    {-1,0,1},
    {1,0,-1}};
int dc[][3] = {
    {0,0,0},
    {0,0,0},
    {-1,-1,-1},
    {1,1,1},
    {1,0,-1},
    {-1,0,1}
    };
int N;
char map[51][51];
int visit[51][51][2][3];  //방향 * 통나무 위치를 포함한 visit

info End  = {0};
info Start = {0};
int Min = INT_MAX;

void solve()
{
    /*
    통나무가 y값이 같은 건지, x값이 같은 건지 판별
    (dir = 0, 1)
    */
    int Sdiff = abs(Start.y[0] - Start.y[1]);
    if(Sdiff == 0) Start.dir = 0;
    else Start.dir = 1;

    queue<info> q;
    q.push(Start);
    for(int i = 0; i < 3; i++)
        visit[Start.y[i]][Start.x[i]][Start.dir][i] = 1;

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        /*
        통나무가 y값이 같은 건지, x값이 같은 건지 판별
        (dir = 0, 1)
        */
        int diff = abs(a.y[0] - a.y[1]);

        //EndCondition
        if(a.y[0] == End.y[0] && a.x[0] == End.x[0] && a.y[1] == End.y[1] && a.x[1] == End.x[1] && a.y[2] == End.y[2] && a.x[2] == End.x[2])
        {
            Min = min(Min, a.count);
            return;
        }

        //방향별로
        for(int i = 0; i < 5; i++)
        {
            info next;

            if(i == 4 && diff > 0)
            {
                for(int j = 0; j < 3; j++)
                {
                    next.y[j] = a.y[j] + dr[5][j];
                    next.x[j] = a.x[j] + dc[5][j];
                } 
            }
            else
            {
                for(int j = 0; j < 3; j++)
                {
                    next.y[j] = a.y[j] + dr[i][j]; 
                    next.x[j] = a.x[j] + dc[i][j];
                }
            }

            next.count = a.count + 1;
            if(i == 4) next.dir = 1 - a.dir;
            else next.dir = a.dir;

            //예외처리
            //예외1. map을 벗어나는 것.
            bool check = true;
            for(int j = 0; j < 3; j++)
            {
                if(!(0 <= next.y[j] && next.y[j] < N && 0 <= next.x[j] && next.x[j] < N))
                {
                    check = false;
                    break;
                }   
            }   
            if(!check) continue;

            //예외2. visit or map이 1인거
            for(int j = 0; j < 3; j++)
            {
                if(visit[next.y[j]][next.x[j]][next.dir][j]) check = false;
                if(map[next.y[j]][next.x[j]] == '1') check = false;
            }
            if(!check) continue;

            //예외3. 회전할 때 3 * 3 체크
            if(i == 4)
            {
                if(diff == 0)
                {
                    for(int y = a.y[0] - 1; y <= a.y[0] + 1; y++)
                    {
                        for(int x = a.x[0]; x <= a.x[2]; x++)
                        {
                            if(!(0 <= y && y < N && 0 <= x && x < N))
                            {
                                check = false;
                            } 
                            if(map[y][x] == '1') 
                            {
                                check = false;
                            }
                        }
                    }
                }
                else
                {
                    for(int y = a.y[0]; y <= a.y[2]; y++)
                    {
                        for(int x = a.x[0] - 1; x <= a.x[0] + 1; x++)
                        {
                            if(!(0 <= y && y < N && 0 <= x && x < N)) check = false;
                            if(map[y][x] == '1') check = false;
                        }
                
                    }
                }
            }
            if(!check) continue;

            for(int i = 0; i < 3; i++)
                visit[next.y[i]][next.x[i]][next.dir][i] = 1;
            q.push(next);
        }
    }
}

int main()
{   
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    int endcount = 0;
    int startcount = 0;
    for(int y = 0; y < N; y++)
    {
        cin >> map[y];
        for(int x = 0; x < N; x++)
        {
            if(map[y][x] == 'E')
            {
                End.y[endcount] = y;
                End.x[endcount++] = x;
            }
            else if(map[y][x] == 'B')
            {
                Start.y[startcount] = y;
                Start.x[startcount++] = x;
            }
        }
    }

    solve();

    if(Min == INT_MAX) cout << 0 << "\n";
    else cout << Min << "\n";

    return 0;
}