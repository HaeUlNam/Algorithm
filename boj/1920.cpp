#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int a[100005];

int binarySearch(int num)
{
    int start = 0;
    int end = N - 1;
    while(1)
    {
        int pivot = (start + end) / 2;

        if(num == a[pivot]) return true;
        if(a[pivot] < num)
        {
            start = pivot + 1;
        }
        else
        {
            end = pivot - 1;
        }

        if(start > end) break;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a, a + N);

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        cout << binarySearch(num) << "\n";
    }

    return 0;
}