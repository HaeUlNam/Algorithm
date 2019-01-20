#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int N;
int result = INT_MAX;
int dp[1001][3];
int arr[1001][3];

int recur(int curHouse, int curColor)
{
    //End Condition
    if(curHouse == N - 1)
        return arr[curHouse][curColor];

    if(dp[curHouse][curColor] != -1)
        return dp[curHouse][curColor];

    int localMin = INT_MAX;
    for(int i = 0; i < 3; i++)
    {
        if(i == curColor) continue;
        localMin = min(localMin, recur(curHouse + 1, i));
    }
    
    return (dp[curHouse][curColor] = localMin + arr[curHouse][curColor]);
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < 3; i++)
        result = min(result, recur(0, i));

    cout << result << endl;

    return 0;
}