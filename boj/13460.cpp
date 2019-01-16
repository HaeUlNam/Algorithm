/*

가장 어려웠던 점은 visit함수의 크기를 얼마큼 줘야할까였다.

처음에 생각하기에는, 2차원 visit 배열을 만들어서 빨간 구슬과 파란 구슬이 다 움직이면
배열에 표시를 해주는 방식으로 생각했다.

아이디어를 얻었는데, 4차원 배열로 선언하는데 1,2는 빨간 구슬, 3,4는 파란 구슬의
위치이다. 이렇게 해서, 모든 부분을 표시할 필요없이 기울어진 그 순간만 체크한다.

*/

#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

struct info{
    int Rx, Ry, Bx, By;
    int count;
};

int  N, M; //세로, 가로
char map[10][11];

int bfs(queue<info> q, info start)
{
    /* Red X, Y / Blue X, Y */
    int visit[10][10][10][10] ={0,};
    int result = -1;

    const int dr[] = {0,0,1,-1};
    const int dc[] = {1,-1,0,0};

    q.push(start);
    visit[start.Rx][start.Ry][start.Bx][start.By] = 1;
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();

        /* End Condition */
        if(cur.count > 10) break;
        if(map[cur.Rx][cur.Ry] == 'O' && map[cur.Bx][cur.By] != 'O')
        {
            result = cur.count;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int Rnr = cur.Rx, Rnc = cur.Ry, Bnr = cur.Bx, Bnc = cur.By;
            
            while(1){
                if(map[Rnr][Rnc] != '#' && map[Rnr][Rnc] != 'O')
                {
                    Rnr += dr[i];
                    Rnc += dc[i];
                }
                else
                {
                    if(map[Rnr][Rnc] == '#')
                    {
                        Rnr -= dr[i];
                        Rnc -= dc[i];
                    }
                    break;
                }
            }

            while(1){
                if(map[Bnr][Bnc] != '#' && map[Bnr][Bnc] != 'O')
                {
                    Bnr += dr[i];
                    Bnc += dc[i];
                }
                else
                {
                    if(map[Bnr][Bnc] == '#')
                    {
                        Bnr -= dr[i];
                        Bnc -= dc[i];
                    }
                    break;
                }
            }

            if(Rnr == Bnr && Rnc == Bnc){
                if(map[Rnr][Rnc] != 'O'){
                   int Rcount = abs(Rnr - cur.Rx) + abs(Rnc - cur.Ry);
                   int Bcount = abs(Bnr - cur.Bx) + abs(Bnc - cur.By);

                   if(Rcount > Bcount){
                       Rnr -= dr[i];
                       Rnc -= dc[i];
                   }
                   else
                   {
                       Bnr -= dr[i];
                       Bnc -= dc[i];
                   }
                }
            }   

            if(visit[Rnr][Rnc][Bnr][Bnc] == 0){
                visit[Rnr][Rnc][Bnr][Bnc] = 1;
                q.push({Rnr, Rnc, Bnr, Bnc, cur.count + 1});
            }
        }
    }
    
    return result;
}

int main()
{
    info start;
    start.count = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> map[i];
        for(int j = 0; j < M; j++)
        {
            if(map[i][j] == 'R')
            {
                start.Rx = i;
                start.Ry = j;
            }
            else if(map[i][j] == 'B')
            {
                start.Bx = i;
                start.By = j;
            }
        }
    }
        
    cout << bfs(queue<info>(), start) << endl;

    return 0;
}