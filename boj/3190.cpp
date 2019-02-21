#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct info{
    int x, y, dir;
};

//동,남,서,북
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int map[105][105];
int N, K;
int L;

int main()
{
    cin >> N >> K;

    int x,y;
    for(int i = 0; i < K; i++)
    {
        cin >> x >> y;
        map[x][y] = 1;
    }

    int X;
    char C;

    vector<info> snake;
    snake.push_back({1,1,0});

    int tCount = 1;
    cin >> L;
    for(int i = 0; ; i++)
    {   
        if(i < L) cin >> X >> C;

        int head = snake.size() - 1;
        int localdir = snake[head].dir;

        bool FF = false;

        for(int j = tCount; ; j++)
        {
            if(i < L && j > X) break;
            //다음 head가 갈 곳
            int nr = dr[localdir] + snake[head].x;
            int nc = dc[localdir] + snake[head].y;

            //예외처리
            if(!(0< nr && nr <= N && 0 < nc && nc <= N))
            {
                FF = true;
                break; 
            }

            for(int k = 0; k < snake.size(); k++)
            {
                if(nr == snake[k].x && nc == snake[k].y)
                {
                    FF = true;
                    break;
                }
            }
            if(FF == true) break;

            //사과 처리
            if(!map[nr][nc])
            {
                stack<info> s;

                for(int k = snake.size() - 1; k >= 1; k--)
                {
                    s.push(snake[k]);
                    snake.pop_back();   
                }
                snake.pop_back();

                while(!s.empty())
                {
                    snake.push_back(s.top());
                    s.pop();
                }
            }
            else
            {
                map[nr][nc] = 0;
            }
            
            snake.push_back({nr,nc,localdir});
            head = snake.size() - 1;
            
            //시간 증가
            tCount++;
            FF = false;
        }
        if(FF == true) break;

        if(C == 'D') snake[head].dir = (snake[head].dir + 1) % 4;
        else if(C == 'L') snake[head].dir = (snake[head].dir + 3) % 4;
    }

    cout << tCount << endl;


    return 0;
}