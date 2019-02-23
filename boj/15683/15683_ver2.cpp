#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct info{
    int x, y, num;
};

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int N, M;
int map[10][10];

int cctvdir[10][4];
vector<info> cctv;
int turnCount[] = {0,4,2,4,4,1};    //바꾸는 방향
int turnNum[] = {0,1,2,2,3,4};      //방향의 개수

int Min = INT_MAX;

int calculate()
{

    int cpy_map[10][10];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cpy_map[i][j] = map[i][j];
        }
    }

    for(int i = 0; i < cctv.size(); i++)
    {
        info cur = cctv[i];

        for(int j = 0; j < turnNum[cur.num]; j++)
        {
            int nr = cur.x;
            int nc = cur.y;
            
            cpy_map[nr][nc] = 100;
            int initdir = cctvdir[i][j];

            while(1)
            {
                nr = nr + dr[initdir];
                nc = nc + dc[initdir];

                if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) break;
                if(map[nr][nc] == 6) break;
                
                cpy_map[nr][nc] = 100;
            }
        }
    }

    int localCount = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(cpy_map[i][j] != 6 && cpy_map[i][j] != 100)
                localCount++;
        }
    }

    return localCount;
}

void recur(int cur)
{
    if(cur >= cctv.size())
    {
        Min = min(calculate(), Min);
        return;
    }

    info cc = cctv[cur];

    for(int i = 0; i < turnCount[cc.num]; i++)
    {
        for(int j = 0; j < turnNum[cc.num]; j++)
            cctvdir[cur][j] = (cctvdir[cur][j] + 1) % 4;

        recur(cur + 1);
    }
}

void dirinit(int cctvNum, int cctvCount)
{
    if(cctvNum == 1) cctvdir[cctvCount][0] = 0;
    else if(cctvNum == 2)
    {
        cctvdir[cctvCount][0] = 0;
        cctvdir[cctvCount][1] = 2;
    }
    else if(cctvNum == 3)
    {
        cctvdir[cctvCount][0] = 0;
        cctvdir[cctvCount][1] = 1;
    }
    else if(cctvNum == 4)
    {
        cctvdir[cctvCount][0] = 0;
        cctvdir[cctvCount][1] = 1;
        cctvdir[cctvCount][2] = 2;
    }
    else
    {
        cctvdir[cctvCount][0] = 0;
        cctvdir[cctvCount][1] = 1;
        cctvdir[cctvCount][2] = 2;
        cctvdir[cctvCount][3] = 3;
    }
}

int main()
{
    cin >> N >> M;

    int cctvCount = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if(1 <= map[i][j] && map[i][j] < 6)
            {
                cctv.push_back({i,j,map[i][j]});
                dirinit(map[i][j], cctvCount);
                cctvCount++;
            }
        }
    }

    recur(0);

    cout << Min << endl;

    return 0;
}