#include<iostream>
using namespace std;

struct info{
    int x, y;
};

int dr[] = {0,0,0,-1,1}; 
int dc[] = {0,1,-1,0,0}; 

int map[25][25];
int arr[7];

info ju;
int N, M, k;

void east()
{
    int temp = arr[3];
    arr[3] = arr[1];
    arr[1] = arr[4];
    arr[4] = arr[6];
    arr[6] = temp;
}

void north()
{
    int temp = arr[2];
    arr[2] = arr[1];
    arr[1] = arr[5];
    arr[5] = arr[6];
    arr[6] = temp;
}

int main()
{   
    cin >> N >> M >> ju.x >> ju.y >> k;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    //명령어 개수만큼 동작
    for(int i = 0; i < k; i++)
    {
        int dir;
        cin >> dir;

        int nr = dr[dir] + ju.x;
        int nc = dc[dir] + ju.y;

        if(!(0 <= nr && nr < N && 0 <= nc && nc < M)) continue;

        //방향에 따라 주사위 값 변경
        if(dir == 1) east();
        else if (dir == 2)
        {
            for(int j = 0; j < 3; j++) east();
        }
        else if (dir == 3) north();
        else
        {
            for(int j = 0; j < 3; j++) north();
        }
            
        //이동한 칸 숫자 체크
        if(!map[nr][nc]) map[nr][nc] = arr[6];
        else
        {
            arr[6] = map[nr][nc];
            map[nr][nc] = 0;
        }

        ju.x = nr;
        ju.y = nc;

        cout << arr[1] << endl;
    }

    return 0;
}