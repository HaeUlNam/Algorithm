#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][3];
int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = N-1; i > 0; i--)
    {
        arr[i - 1][0] += min(arr[i][1], arr[i][2]);
        arr[i - 1][1] += min(arr[i][0], arr[i][2]);
        arr[i - 1][2] += min(arr[i][0], arr[i][1]);
    }

    cout << min(arr[0][0], min(arr[0][1], arr[0][2])) << endl;

    return 0;
}