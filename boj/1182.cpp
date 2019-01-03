#include<iostream>
using namespace std;

int N, S;
int resultCount;
int arr[21];

void recur(int cur, int sum)
{
    if(cur >= N)
    {
        if(sum == S)
        {
            resultCount++;
        }
        return;
    }

    recur(cur + 1, sum + arr[cur]);
    recur(cur + 1, sum);
}
int main()
{
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(S == 0) resultCount--;
    recur(0,0);

    cout << resultCount << endl;

    return 0;
}