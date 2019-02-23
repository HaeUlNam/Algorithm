#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct info{
    int x,y, tCount;
};

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int R,C;

info D,S;
vector<info> water;

char map[52][52];
int visit[52][52];
int result;

bool bfs()
{
    queue<info> q;
    visit[S.x][S.y] = 1;
    q.push(S);

    int localCount = 0;
    while(!q.empty())
    {
        info aa = q.front();
        q.pop();

        if(aa.tCount == localCount)
        {
            vector<info> temp = water;

            //Water 퍼지는 곳
            for(int i = 0; i< temp.size(); i++)
            {
                info b = temp[i];

                for(int j = 0; j < 4; j++)
                {
                    int nr = b.x + dr[j];
                    int nc = b.y + dc[j];
                    
                    if(!(0 <= nr && nr < R && 0 <= nc && nc < C)) continue;
                    if(map[nr][nc] == '*') continue;
                    if(map[nr][nc] == 'X') continue;
                    if(map[nr][nc] == 'D') continue;

                    map[nr][nc] = '*';
                    water.push_back({nr,nc});
                }
            }

            localCount++;
        }

        //고슴도치 움직이기
        for(int i = 0; i < 4; i++)
        {
            int nr = aa.x + dr[i];
            int nc = aa.y + dc[i];
            
            if(!(0 <= nr && nr < R && 0 <= nc && nc < C)) continue;
            if(map[nr][nc] == '*') continue;
            if(map[nr][nc] == 'X') continue;
            if(visit[nr][nc] == 1) continue;

            if(map[nr][nc] == 'D')
            {
                result = aa.tCount;
                return true;
            }

            visit[nr][nc] = 1;
            q.push({nr,nc,aa.tCount + 1});
        }
    }

    return false;
}

int main()
{
    cin >> R >> C;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'D')        D = {i,j,0};
            else if(map[i][j] == 'S')   S = {i,j,0};
            else if(map[i][j] == '*')   water.push_back({i,j,0});
        }
    }

    if(bfs()) cout << result + 1 << endl;
    else      cout << "KAKTUS" << endl;

    return 0;
}