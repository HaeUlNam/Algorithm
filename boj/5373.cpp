#include<iostream>
#include<vector>

#define Up 3
#define Down 6
#define Front 5
#define Back 1
#define Left 2
#define Right 4

using namespace std;

char map[7][4][4];
char mmun[7] = {'.','o','g','w','b','r','y'};

void init()
{
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                map[i][j][k] = mmun[i];
            }
        }
    }
}

void turnUp()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[5][1][i];
        map[5][1][i] = map[4][j][1];
        map[4][j][1] = map[1][3][j];
        map[1][3][j] = map[2][i][3];
        map[2][i][3] = tmp;
    }
}

void turnFront()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[6][1][i];
        map[6][1][i] = map[4][3][j];
        map[4][3][j] = map[3][3][j];
        map[3][3][j] = map[2][3][j];
        map[2][3][j] = tmp;
    }
}

void turnRight()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[6][i][3];
        map[6][i][3] = map[1][i][3];
        map[1][i][3] = map[3][i][3];
        map[3][i][3] = map[5][i][3];
        map[5][i][3] = tmp;
    }
}

void turnLeft()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[6][i][1];
        map[6][i][1] = map[5][i][1];
        map[5][i][1] = map[3][i][1];
        map[3][i][1] = map[1][i][1];
        map[1][i][1] = tmp;
    }
}

void turnBack()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[6][3][j];
        map[6][3][j] = map[2][1][i];
        map[2][1][i] = map[3][1][i];
        map[3][1][i] = map[4][1][i];
        map[4][1][i] = tmp;
    }
}

void turnDown()
{
    for(int i = 1, j = 3; i <= 3; i++, j--)
    {
        int tmp = map[1][1][i];
        map[1][1][i] = map[4][i][3];
        map[4][i][3] = map[5][3][j];
        map[5][3][j] = map[2][j][1];
        map[2][j][1] = tmp;
    }
}

void turnMun(int mun)
{
    int tmp = map[mun][1][1];
    map[mun][1][1] = map[mun][3][1];
    map[mun][3][1] = map[mun][3][3];
    map[mun][3][3] = map[mun][1][3];
    map[mun][1][3] = tmp;

    int ttmp = map[mun][1][2];
    map[mun][1][2] = map[mun][2][1];
    map[mun][2][1] = map[mun][3][2];
    map[mun][3][2] = map[mun][2][3];
    map[mun][2][3] = ttmp;
}

void top(char mun, char dir)
{
    if(mun == 'U')
    {   
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnUp();
            turnMun(Up);
        }
    }
    else if(mun == 'D')
    {
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnDown();
            turnMun(Down);
        }
    }
    else if(mun == 'F')
    {
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnFront();
            turnMun(Front);
        }
    }
    else if(mun == 'B')
    {
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnBack();
            turnMun(Back);
        }
    }
    else if(mun == 'L')
    {
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnLeft();
            turnMun(Left);
        }
    }
    else if(mun == 'R')
    {
        int count;
        if(dir == '+') count = 1;
        else count = 3;

        for(int i = 0; i < count; i++)
        {
            turnRight();
            turnMun(Right);
        }
    }
}


void printUp()
{
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cout << map[Up][i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for(int x = 0; x < testcase; x++)
    {
        int n;
        cin >> n;

        init();

        for(int y = 0; y < n; y++)
        {
            char mun, dir;
            cin >> mun >> dir;

            top(mun, dir);
        }
        printUp();
    }

    return 0;
}

