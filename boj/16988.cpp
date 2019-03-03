#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct info{
    int y, x; 
};  

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};  

int N, M;
int visit[21][21]; 
int Map[21][21];

vector<info> twos;
vector<info> group [401]; //이차원 배열
int groupnum;

vector<info> ones;

int Max = INT_MIN;

void grouping(info a)
{   
    for(int i = 0; i < 4; i++)
    {
        int nr = a.y + dy[i];
        int nc = a.x + dx[i];

        if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) continue;
        if(Map[nr][nc] != 2) continue;
        if(visit[nr][nc]) continue;

        info bb;
        bb.y = nr; bb.x = nc;

        visit[nr][nc] = 1;
        group[groupnum].push_back(bb);
        grouping(bb);
    }   
}

int calculate()
{
    int cpy_Map[21][21] = {0};
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cpy_Map[i][j] = Map[i][j];
        }
    }

    cpy_Map[ones[0].y][ones[0].x] = 1;
    cpy_Map[ones[1].y][ones[1].x] = 1;

    int result = 0;

    for(int i = 0; i < groupnum; i++)
    {
        bool check = false;
        for(int j = 0; j < group[i].size(); j++)
        {
            info a = group[i][j];
            for(int k = 0; k < 4; k++)
            {
                int nr = a.y + dy[k];
                int nc = a.x + dx[k];

                if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) continue;
                if(cpy_Map[nr][nc] == 0)
                {
                    check = true;
                    break;
                }
            }
            if(check) break;
        }

        if(!check) result += group[i].size();
    }

    return result;
}

void putOne(int v, info s)
{
    if(v >= 2)
    {
        Max = max(Max, calculate());
        return;
    }

    int i = s.y;
    int j = s.x;

    for(int i = s.y; i < N; i++)
    {
        while(j < M)
        {
            if(Map[i][j] != 0) 
            {
                j++;
                continue;
            }
            
            info a;
            a.y = i; a.x = j;
            ones.push_back(a);

            a.x += 1;
            if(a.x >= M)
            {
                a.x = 0;
                a.y += 1;
            }
            putOne(v + 1, a);
            ones.pop_back();
            j++;
        }

        j = 0;
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
            if(Map[i][j] == 2)
            {
                info a;
                a.y = i; a.x = j;
                twos.push_back(a);
            }
        }
    }

    //grouping
    for(int i = 0; i < twos.size(); i++)
    {
        info a = twos[i];
        if(visit[a.y][a.x]) continue;

        visit[a.y][a.x] = 1;
        group[groupnum].push_back(a);
        grouping(a);
        groupnum++;
    }

    info ss; ss.y = 0; ss.x = 0;
    putOne(0, ss);

    if(Max ==  INT_MIN) cout << 0 << endl; 
    else cout << Max << endl;
    
    return 0;
}