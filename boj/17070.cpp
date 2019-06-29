#include<iostream>
using namespace std;

/*0 : 세로, 1 : 가로, 2: 세로*/

struct info{
    int y, x;
};

int N;
int map[17][17];

int result;

void solve(info a, int dir)
{
    if(a.y == N -1 && a.x == N -1)
    {
        result++;
        return;
    }

    if(dir == 0)//세로
    {
        if(a.y + 1 < N && !map[a.y + 1][a.x])
        {
            solve({a.y + 1, a.x}, 0);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
    else if(dir == 1)//가로
    {
        if(a.x + 1 < N && !map[a.y][a.x + 1])
        {
            solve({a.y, a.x + 1}, 1);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
    else if(dir == 2)//대각선
    {
        if(a.y + 1 < N && !map[a.y + 1][a.x])
        {
            solve({a.y + 1, a.x}, 0);
        }
        if(a.x + 1 < N && !map[a.y][a.x + 1])
        {
            solve({a.y, a.x + 1}, 1);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> map[y][x];
        }
    }

    solve({0,1}, 1);

    cout << result << "\n";

    return 0;
}