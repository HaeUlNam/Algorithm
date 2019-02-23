#include<iostream>
#include<vector>
using namespace std;

struct info{
    int x,y;
};

int map[10][10];
int visitCol[10][10];
int visitRow[10][10];
int visitSquare[10][10];

vector<info> zero;

bool recur(int v)
{
    if(v >= zero.size()) return true;

    info aa = zero[v];

    for(int i = 1; i <= 9; i++)
    {
        if(visitCol[aa.y][i]) continue;
        if(visitRow[aa.x][i]) continue;
        int bb = ((aa.x / 3) * 3) + aa.y / 3;
        if(visitSquare[bb][i]) continue;

        map[aa.x][aa.y] = i;
        visitCol[aa.y][i] = 1;
        visitRow[aa.x][i] = 1;
        visitSquare[bb][i] = 1;

        if(recur(v + 1)) return true;   

        map[aa.x][aa.y] = 0;
        visitCol[aa.y][i] = 0;
        visitRow[aa.x][i] = 0;
        visitSquare[bb][i] = 0;
    }

    return false;
}

int main()
{   
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 0)
            {
                zero.push_back({i,j});
            }
            else
            {
                visitCol[j][map[i][j]] = 1;
                visitRow[i][map[i][j]] = 1;

                //영역 구하기 공식
                int bb = ((i / 3) * 3) + j / 3;
                visitSquare[bb][map[i][j]] = 1;
            }
        }
    }

    recur(0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}