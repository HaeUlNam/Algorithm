#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct info{
    int x,y,num;
};

//동 남 서 북
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

vector<vector<int>> map;

int N, M;

vector < vector < int > > init = {{0},{0},{0,2},{0,3},{0,2,3},{0,1,2,3}};
vector<int> turn = {0,4,2,4,4,1};

vector<info> cctv;
vector<int> state(8);

int Min = INT_MAX;

int calculate()
{
    vector<vector<int>> cpy_map = map;

    //cctv 카메라 수만큼
    for(int i = 0; i < cctv.size(); i++)
    {
        info aa = cctv[i];
        vector<int> localdir = init[aa.num];
        
        //각각 카메라마다의 감시 방향만큼
        for(int j = 0; j < localdir.size(); j++)
        {
            int ddir = (localdir[j] + state[i]) % 4;

            int nr = aa.x;
            int nc = aa.y;

            cpy_map[nr][nc] = '#';
            
            while(1)
            {
                nr = nr + dr[ddir];
                nc = nc + dc[ddir];

                if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) break;
                if(cpy_map[nr][nc] == 6) break;
                
                cpy_map[nr][nc] = '#';            
            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(cpy_map[i][j] == 0) count++;
        }
    }

    return count;
}

void recur(int v)
{
    if(v >= cctv.size())
    {
        Min = min(calculate(), Min);
        return;
    }

    int count = turn[cctv[v].num];

    for(int i = 0; i < count; i++)
    {
        state[v] = i;
        recur(v + 1);
    }
}

int main()
{
    cin >> N >> M;

    map = vector < vector < int > > (N, vector < int > ( M ) );
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if(1 <= map[i][j] && map[i][j] <= 5)
                cctv.push_back({i,j,map[i][j]});
        }
    }

    recur(0);

    cout << Min << endl;

    return 0;
}