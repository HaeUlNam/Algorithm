#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

struct info{
    int x, y, num;
};

struct Move{
    int x, y, dir;
};

//북, 동, 남, 서
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

//+1로 방향 전환
int Carr[5][5] ={{1}, {1,3}, {0,1}, {0,1,3}, {0,1,2,3}};

int dirNum[] = {1,2,2,3,4};
int rota[] = {4,2,4,4,1};

int N, M;
vector<info> cctv;

int Min = INT_MAX;

int calculate(int visit[][9])
{
    int count = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(!visit[i][j]) count++;

    return count;
}

void solve(int cur, int visit[][9])
{
    if(cur >= cctv.size())
    {
        int local = calculate(visit);
        if(local < Min)
            Min = local;
        return;
    }

    //Copy Visit
    int cpyVisit[9][9] = {0};
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cpyVisit[i][j] = visit[i][j];

    info aa = cctv[cur];

    //회전 횟수만큼 돈다.
    for(int i = 0; i < rota[aa.num]; i++)
    {
        queue <Move> q;

        cpyVisit[aa.x][aa.y] = -1;

        //방향 개수만큼 push
        for(int j = 0; j < dirNum[aa.num]; j++){
            q.push({aa.x, aa.y, (Carr[aa.num][j] + i) % 4});
        }

        while(!q.empty()){
            Move bb = q.front();
            q.pop();

            if(!(0 <= bb.x && bb.x < N && 0 <= bb.y && bb.y < M)) continue;
            if(cpyVisit[bb.x][bb.y] == 6) continue;

            cpyVisit[bb.x][bb.y] = -1;

            int nr = bb.x + dr[bb.dir];
            int nc = bb.y + dc[bb.dir];

            q.push({nr,nc,bb.dir});
        }

        solve(cur + 1, cpyVisit);

        //Init
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cpyVisit[i][j] = visit[i][j];
    }
}

int main()
{
    //Input
    cin >> N >> M;

    int visit[9][9] = {0};

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> visit[i][j];
            if( 0 < visit[i][j] && visit[i][j] < 6)
                cctv.push_back({i,j, visit[i][j] - 1});
        }
    }

    solve(0,visit);

    cout << Min << endl;

    return 0;
}