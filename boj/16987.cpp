#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int N;
int egg[10][2];

vector<int> local;
int Max = INT_MIN;

int calculate()
{
    int cpy_egg[10][2] = {0};
    for(int i = 0; i < N; i++)
    {
        cpy_egg[i][0] = egg[i][0];
        cpy_egg[i][1] = egg[i][1];
    }

    for(int i = 0; i < N; i++)
    {
        int _minus = local[i];
        if(cpy_egg[i][0] <= 0) continue;
        if(cpy_egg[_minus][0] <= 0) continue;
    
        cpy_egg[_minus][0] -= cpy_egg[i][1];
        cpy_egg[i][0] -= cpy_egg[_minus][1];
    }

    int result = 0;
    for(int i = 0; i < N; i++)
    {
        if(cpy_egg[i][0] <= 0) result++;
    }

    return result;
}

void recur(int v)
{
    if(v >= N)
    {
        Max = max(Max, calculate());
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(i == v) continue;

        local.push_back(i);
        recur(v + 1);
        local.pop_back();
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> egg[i][0] >> egg[i][1];

    recur(0);

    if(Max == INT_MIN) cout << 0 << '\n';
    else cout << Max << '\n';

    return 0;
}