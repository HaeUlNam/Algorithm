#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#include<vector>
using namespace std;

struct info{
    int x, y;
};

int dr[] = {0, 0, 1, -1};
int dc[] = {1,-1, 0,  0};

int N, L, R;
int map[53][53];
int visit[53][53]; 

queue<info> q;
vector< stack < info > > vec;
vector< int > avg;

int moveCount;

void print()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int x, int y, int visit[][51])
{
    stack<info> local;
    int sum = 0;

    visit[x][y] = 1;
    q.push({x,y});
    local.push({x,y}); 
    sum += map[x][y];

    while(!q.empty())
    {   
        info aa = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = aa.x + dr[i];
            int nc = aa.y + dc[i];

            if(!(0 < nr && nr <= N && 0 < nc && nc <= N)) continue;
            if(visit[nr][nc]) continue;
            int diff = abs(map[aa.x][aa.y] - map[nr][nc]);
            if(!(L <= diff && diff <= R)) continue;

            visit[nr][nc] = 1;
            q.push({nr,nc});
            local.push({nr,nc});
            sum += map[nr][nc];
        }
    }

    if(local.size() != 1) 
    {
        vec.push_back(local);
        int count = local.size();
        avg.push_back(sum / count);
        //cout << sum / count << endl;
    }
}

void Calculate()
{
    // print();
    for(int i = 0; i < vec.size(); i++)
    {
        stack<info> ss = vec[i];

        while(!ss.empty())
        {
            info aa = ss.top();
            ss.pop();
            map[aa.x][aa.y] = avg[i];
        }
        // print();
    }
    //cout << "-------------------------------------" << endl;
}

int main()
{
    //Input
    cin >> N >> L  >> R;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <=N; j++)
        {
            cin >> map[i][j];
        }
    }

    while(1)
    {
        int visit[51][51] = {0, };

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j<= N; j++)
            {  
                if(visit[i][j]) continue;
                bfs(i, j, visit);
            }
        }
        
        if(vec.empty()) break;
        
        Calculate();
        moveCount++;

        //init
        vec.clear();
        avg.clear();
    }

    cout << moveCount << endl;

    return 0;
}