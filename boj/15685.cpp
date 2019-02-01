#include<iostream>
#include<vector>
using namespace std;

//오른쪽, 위쪽, 왼쪽, 아래쪽
int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};
int N;

int visit[101][101];

//오른쪽, 아래쪽, 왼쪽, 위쪽
int checkdr[] = {0,1,0,-1};
int checkdc[] = {1,0,-1,0};

int result;

void check()
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(visit[i][j] && visit[i + 1][j] && visit[i][j + 1] && visit[i + 1][j + 1]) result++;
        }
    }
}

void solve(int x, int y, int d, int g)
{
    vector<int> dirs = {d};

    //Check right dir & reverse dir
    visit[y][x] = 1;
    y = y + dr[d];
    x = x + dc[d];
    visit[y][x] = 1;

    for(int i = 0; i < g; i++)
    {
        int init = dirs.size() - 1;
        for(int j = init; j >= 0; j--)
        {
            int localdir = (dirs[j] + 1) % 4;
            dirs.push_back(localdir);

            visit[y][x] = 1;
            y = y + dr[localdir];
            x = x + dc[localdir];
            visit[y][x] = 1;
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        solve(x,y,d,g);
    }

    check();
    cout << result << endl;

    return 0;
}