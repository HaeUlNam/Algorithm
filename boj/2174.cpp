#include<iostream>
#include<vector>
using namespace std;

struct info{
    int y,x,dir;
};

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int A, B;
int N, M;

int map[102][102];
vector<info> robot(105);

bool ExcuteCommand(int num, char command, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(command == 'L')
            robot[num].dir = (robot[num].dir + 3) % 4;
        else if(command == 'R')
            robot[num].dir = (robot[num].dir + 1) % 4;
        else
        {
            int nr = robot[num].y + dr[robot[num].dir];
            int nc = robot[num].x + dc[robot[num].dir];

            if(!(0 < nr && nr <= B && 0 < nc && nc <= A))
            {
                cout << "Robot " << num << " crashes into the wall" << endl;
                return false;
            }
            if(map[nr][nc]!= 0)
            {
                cout << "Robot " << num << " crashes into robot " << map[nr][nc] << endl;
                return false;   
            }

            map[nr][nc] = map[robot[num].y][robot[num].x];
            map[robot[num].y][robot[num].x] = 0;

            robot[num].y = nr;
            robot[num].x = nc;
        }
    }

    return true;
}

int main()
{
    cin >> A >> B;
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        int x, y;
        char ddir;
        cin >> x >> y >> ddir;
        
        map[y][x] = i;
        robot[i].y = y; robot[i].x = x;

        if(ddir == 'N') robot[i].dir = 0;
        else if(ddir == 'E') robot[i].dir = 1;
        else if(ddir == 'S') robot[i].dir = 2;
        else if(ddir == 'W') robot[i].dir = 3;
    }

    for(int i = 0; i < M; i++)
    {
        int num, count;
        char command;
        
        cin >> num >> command >> count;

        if(!ExcuteCommand(num, command, count))
            return 0;
    }

    cout << "OK" << endl;

    return 0;
}

/*
실수한 부분 : x, y가 아래에서부터 1,1인 걸 까먹었다.
           결과적으로 문제를 제대로 안 읽은 것!!!
*/