#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//실수한 점 : flag, 0일 때 움직인 것.

//북,남,서,동
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int Searchdr[] = {0,0,1,1};
int Searchdc[] = {1,1,0,0};

int N;
int map[21][21];

vector<int> dirs;

int result = INT_MIN;

int calculate()
{
    int cpy_map[21][21];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cpy_map[i][j] = map[i][j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        int flag[21][21] = {0};
        

        int Dir = dirs[i];
        int x, y;
        if(Dir == 0 || Dir == 2) {x = 0; y = 0;}
        else if(Dir == 1) {x = N-1; y = 0;}
        else {x = 0; y = N-1;}

        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                int cpyx = x;
                int cpyy = y;

                while(cpy_map[cpyx][cpyy] != 0)
                {
                    int befox = cpyx;
                    int befoy = cpyy;

                    cpyx = cpyx + dr[Dir];
                    cpyy = cpyy + dc[Dir];

                    if(!(0 <= cpyx && cpyx < N && 0 <= cpyy && cpyy < N)) break;
                    if(flag[cpyx][cpyy] == 1) break;
                    if(cpy_map[cpyx][cpyy] == cpy_map[befox][befoy])
                    {
                        flag[cpyx][cpyy] = 1;
                        cpy_map[cpyx][cpyy] *= 2;
                        cpy_map[befox][befoy] = 0;    
                        break;
                    }
                    if(cpy_map[cpyx][cpyy] != 0) break;
                    
                    cpy_map[cpyx][cpyy] = cpy_map[befox][befoy];
                    cpy_map[befox][befoy] = 0;
                }
                x += Searchdr[Dir];
                y += Searchdc[Dir];
            }
            

            if(Dir == 0){ x += 1; y = 0;}
            else if(Dir == 1) { x -= 1; y = 0;}
            else if(Dir == 2) { x = 0; y += 1;}
            else { x = 0; y -= 1;}
        }
    }

    int Max = INT_MIN;
    for(int j = 0; j < N; j++)
    {
        for(int k = 0; k < N; k++)
        {
            if(Max < cpy_map[j][k])
            {
                Max = cpy_map[j][k];
            }
        }
    }

    return Max;
}

void recur(int v)
{
    if(v >= 5)
    {
        result = max(calculate(), result);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        dirs.push_back(i);
        recur(v + 1);
        dirs.pop_back();
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

    recur(0);

    cout << result << endl;

    return 0;
}