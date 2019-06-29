#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct info{
    int x, y, z;
    int num;
};

int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};

int map[5][5][5];
int calmap[5][5][5];
int result = INT_MAX;

int panVisit[5];
vector<int> pan;

int rotVisit[5];
vector<int> rot;

int bfs()
{
    int rrresult = INT_MAX;

    queue<info> q;
    int visit[5][5][5] = {0};

    if(calmap[0][0][0])
    {
        visit[0][0][0] = 1;
        info ccc = {0,0,0,0};
        q.push(ccc);
    }

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        if(a.x == 4 && a.y == 4 && a.z == 4)
        {
            rrresult = a.num;
            break;
        }

        for(int i = 0; i < 6; i++)
        {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            int nz = a.z + dz[i];

            if(!(0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5)) continue;
            if(!calmap[nx][ny][nz]) continue;
            if(visit[nx][ny][nz]) continue;
            
            // cout << nx << "/"<< ny << "/"<<nz << "\n";
            info ddd = {nx, ny, nz, a.num + 1};
            visit[nx][ny][nz] = 1;
            q.push(ddd);
        }
        
    }

    return rrresult;
}

void rotate(int cc, int num)
{   
    int tmp[5][5] = {0};

    for(int a = 0; a < num; a++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                tmp[j][k] = calmap[cc][5 - k - 1][j]; 
            }
        }

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                calmap[cc][i][j] = tmp[i][j];
            }
        }
    }
}

void calculate()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                calmap[i][j][k] = map[pan[i]][j][k];
            }   
        }   
    }

    for(int i = 0; i < 5; i++)
        rotate(i, rot[i]);
}

void rotateSolve(int v)
{
    if(v >= 5)
    {
            calculate();
        result = min(result, bfs());
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        rot.push_back(i);
        rotateSolve(v + 1);
        rot.pop_back();
    }
}

void solve(int v)
{
    if(v >= 5)
    {
        rotateSolve(0);
        return;
    }

    for(int i = 0; i < 5; i++)
    {
        if(panVisit[i]) continue;

        panVisit[i] = 1;
        pan.push_back(i);
        solve(v + 1);
        pan.pop_back();
        panVisit[i] = 0;
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                cin >> map[i][j][k];
            }   
        }   
    }
    
    solve(0);

    if(result == INT_MAX) cout << -1 << "\n";
    else cout << result << "\n";

    return 0;
}