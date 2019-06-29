#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;
#define MAX_ROW 55       
#define MAX_COL 55       

//동, 남, 서, 북
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

struct info{
    int y, x;
};

int N, L, R;

int map[MAX_ROW][MAX_COL];
int cpy_map[MAX_ROW][MAX_COL];
int visit[MAX_ROW][MAX_COL];

bool check = true;

void bfs(info start)
{
    vector<info> move;
    move.push_back(start);

    queue<info> q;
    q.push(start);
    visit[start.y][start.x] = 1;

    //연합 찾기
    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = dy[i] + a.y;
            int nc = dx[i] + a.x;

            int diff = abs(map[nr][nc] - map[a.y][a.x]);

            //Exception Handling
            if(!(0 < nr && nr <= N && 0 < nc && nc <= N)) continue;
            if(visit[nr][nc]) continue;
            if(!(L <= diff && diff <= R)) continue; 
            
            visit[nr][nc] = 1;
            info aa; aa.y = nr; aa.x = nc;
            q.push(aa);
            move.push_back(aa);
        }
    }

    //연합 값
    int sum = 0;
    int count = move.size();
    
    if(count == 1) return;

    check = true;

    for(int i = 0; i < count; i++)
    {
        info aa = move[i];
        sum += map[aa.y][aa.x];
    }
    
    sum /= count;

    for(int i = 0; i < count; i++)
    {
        info aa = move[i];
        cpy_map[aa.y][aa.x] = sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> L >> R;

    //input
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> map[y][x];
            cpy_map[y][x] = map[y][x];
        }
    }

    int count = -1;
    while(check)
    {
        check = false;

        for(int y = 1; y <= N; y++)
        {
            for(int x = 1; x <= N; x++)
            {
                if(visit[y][x]) continue;

                info start;
                start.y = y; start.x = x;
                bfs(start);
            }
        }

        // cout << "\n";
        //복사
        for(int y = 1; y <= N; y++)
        {
            for(int x = 1; x <= N; x++)
            {
                map[y][x] = cpy_map[y][x];
                visit[y][x] = 0;
                // cout << map[y][x] << " ";
            }
            // cout << "\n";
        }
        count++;
    }
    
    cout << count << endl;

    return 0;
}
