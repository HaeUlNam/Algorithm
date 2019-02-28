#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct info{
    int y, x, dir, command;
};

//동, 남, 서, 북
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

//현재, 왼쪽, 오른쪽, 반대
int d[] = {0,1,3,2};
int dcost[] = {0,1,1,2};

int M, N;

int map[105][105];
int visit[105][105][4];

info start, eend;
info result;

int bfs()
{
    queue<info> q;
    q.push(start);

    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        //최단거리
        if(a.y == eend.y && a.x == eend.x && a.dir == eend.dir)
        {
            result = a;
            break;
        }

        for(int j = 1; j <= 3; j++)
        {   
            int nr = a.y + dr[a.dir] * j;
            int nc = a.x + dc[a.dir] * j;

            if(!(0 < nr && nr <= M && 0 < nc && nc <= N)) break;
            if(visit[nr][nc][a.dir]) continue;
            if(map[nr][nc]) break;

            visit[nr][nc][a.dir] = 1;
            q.push({nr,nc,a.dir,a.command + 1});
        }

        for(int i = 1; i < 4; i++)
        {
            int dir = (a.dir + d[i]) % 4;
            int cost = a.command + dcost[i];

            if(visit[a.y][a.x][dir]) continue;
            visit[a.y][a.x][dir] = 1;
            q.push({a.y,a.x, dir,cost});
        }
    }

    return result.command;    
}

int convertDir(int dir)
{
    if(dir == 1) return 0;  //동
    if(dir == 2) return 2;  //서
    if(dir == 3) return 1;  //남
    if(dir == 4) return 3;  //북

    return -1;
}

int main()
{   
    //입력
    cin >> M >> N;

    for(int y = 1; y <= M; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> map[y][x];
        }
    }

    cin >> start.y >> start.x >> start.dir;
    cin >> eend.y >> eend.x >> eend.dir;

    start.command = 0; eend.command = 0;
    //방향 내 알고리즘에 맞게 변형
    start.dir = convertDir(start.dir);
    eend.dir = convertDir(eend.dir);

    cout << bfs() << endl;

    return 0;
}

/*

건너뛰게 해도 된다.
-> map말고, visit를..

방향이 있으니깐, visit배열도 3차원으로 [][][4]와 같이 만들어야 한다.
-> visit을 이와 같이 하는 이유는 방향을 돌리는데, cost가 들기에..(최단을 좌우한다.)
-> https://www.acmicpc.net/board/view/33301 참고..

bfs의 기본원리를 생각해보자.
-> 여기서, 순차적으로 값이 늘어나서 최소를 찾을 수 있게 하여야 되는데 그렇게 하지 못했다.
-> bfs로 최단, 최소를 구할 때, queue의 값이 순차적으로 증가하는지 봐야 한다.
*/