#include <iostream>
#include <algorithm>
#include <cstdlib> // abs()
#include <climits>
using namespace std;

int N;
int Sarr[11];
int Larr[11];
int S[22][22];
int Min = INT_MAX;

int calculate()
{
    int lim = N/2;
    //Steam
    int Stotal = 0;
    for(int i = 0; i < lim; i++)
    {
        for(int j = i + 1; j < lim; j++)
        {
            int x = Sarr[i];
            int y = Sarr[j];

            Stotal += (S[x][y] + S[y][x]);
        }   
    }

    //Lteam
    int Ltotal = 0;
    for(int i = 0; i < lim; i++)
    {
        for(int j = i + 1; j < lim; j++)
        {
            int x = Larr[i];
            int y = Larr[j];

            Ltotal += (S[x][y] + S[y][x]);
        }   
    }

    return abs(Stotal - Ltotal);
}

/* Start team first */
void recur(int cur, int Scount, int Lcount)
{
    if(Scount > N/2 || Lcount > N/2) return;

    if(cur > N)
    {
        Min = min(calculate(), Min);
        return;
    }

    Sarr[Scount] = cur;
    recur(cur + 1, Scount + 1, Lcount);

    Larr[Lcount] = cur;
    recur(cur + 1, Scount, Lcount + 1);
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> S[i][j];
        }
    }

    /* 중복되는 조합의 개수를 줄이고자, 1을 넣고 시작한다. */
    Sarr[0] = 1;
    recur(2, 1, 0);

    cout << Min << endl;

    return 0;
}