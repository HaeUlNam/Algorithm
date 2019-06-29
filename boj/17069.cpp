#include<iostream>
using namespace std;

/*0 : 세로, 1 : 가로, 2: 세로*/

struct info{
    int y, x;
};

int N;
int map[33][33];

long long dp[33][33][3];

long long result;

long long solve(info a, int dir)
{
    if(a.y == N -1 && a.x == N -1)
    {
        return 1;
    }

    long long & local = dp[a.y][a.x][dir];
    if(local != -1) return local;
    local = 0;

    if(dir == 0)//세로
    {
        if(a.y + 1 < N && !map[a.y + 1][a.x])
        {
            local += solve({a.y + 1, a.x}, 0);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                local += solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
    else if(dir == 1)//가로
    {
        if(a.x + 1 < N && !map[a.y][a.x + 1])
        {
            local += solve({a.y, a.x + 1}, 1);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                local += solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
    else if(dir == 2)//대각선
    {
        if(a.y + 1 < N && !map[a.y + 1][a.x])
        {
           local += solve({a.y + 1, a.x}, 0);
        }
        if(a.x + 1 < N && !map[a.y][a.x + 1])
        {
            local += solve({a.y, a.x + 1}, 1);
        }
        if(a.y + 1 < N && a.x + 1 < N)
        {
            if(!map[a.y + 1][a.x] && !map[a.y][a.x + 1] && !map[a.y + 1][a.x + 1])
            {
                local += solve({a.y + 1, a.x + 1}, 2);
            }
        }
    }
    
    return local;
}

int main()
{
    cin >> N;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> map[y][x];
            
            dp[y][x][0] = -1;dp[y][x][1] = -1;dp[y][x][2] = -1;
        }
    }

    result = solve({0,1}, 1);

    cout << result << "\n";

    return 0;
}