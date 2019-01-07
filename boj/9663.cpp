#include<iostream>
#include<cstdlib> // abs()
using namespace std;

int N;
int col[15];
int Count;

bool isPossible(int row)
{
    for(int i = 1; i < row; i++)
    {
        //같은 column
        if(col[i] == col[row]) return false;

        //대각선
        if((row - i) == abs(col[row] - col[i])) return false;
    }

    return true;
}

void solve(int row)
{
    if(row > N)
    {  
        Count++;
        return;
    }

    for(int i = 1; i<= N; i++)
    {
        col[row] = i;
        if(isPossible(row))
        {
            solve(row + 1);
        }
        else
        {
            col[row] = 0;
        }

    }
}

int main()
{
    cin >> N;
    solve(1);

    cout << Count << endl;

    return 0;
}