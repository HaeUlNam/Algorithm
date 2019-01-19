//1, 5, 9, 13 : 4n-3
//재귀 함수 이용
//좌표는 x+2, y+2

#include <iostream>
using namespace std;

struct info{
    int x, y;
};

//동,남,서,북
int dr[] = {0,1,0,-1};
int dc[] = {1,0,0-1,0};

int N;
char arr[500][500];

void recur(int num, info point)
{
    //End Condition 
    if(num < 1) return;
    
    int nr = point.x, nc = point.y;
    arr[nr][nc] = '*';
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < num - 1; j++)
        {
            nr += dr[i];
            nc += dc[i];

            arr[nr][nc] = '*';
        }
    }

    recur(num - 4, {point.x + 2, point.y + 2});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int Max = 4 * N;

    for(int i = 0; i < Max; i++)
    {
        for(int j = 0; j < Max; j++)
        {
            arr[i][j] = ' ';
        }
    }

    recur(Max - 3, {0,0});

    for(int i = 0; i < Max - 3; i++)
    {
        for(int j = 0; j < Max - 3; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;   
    }

    return 0;
}