#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int arr[1000005];
int N;

void swap(int * a, int * b)
{
    int tmp = * a;
    *a = *b;
    *b = tmp;
}

int randomPivot(int start, int end)
{
    int diff = end - start;
    int randomNum = rand() % (diff + 1);

    return start + randomNum;
}

int Partition(int start, int end)
{
    int pivotidx = randomPivot(start, end);
    
    swap(arr[start], arr[pivotidx]);
    pivotidx = start;
    
    int pivot = arr[start];
    int i = start;
    int j = start + 1;

    for(;j <= end;j++)
    {
        if(arr[j] < pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    //pivot을 자신의 위치로 옮긴다.
    swap(arr[pivotidx], arr[i]);

    return i;
}

void QuickSort(int start, int end)
{
    if(start < end)
    {
        int mid = Partition(start, end);

        QuickSort(start, mid - 1);
        QuickSort(mid + 1, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    srand((unsigned)time(NULL));

    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    QuickSort(1, N);

    for(int i = 1; i <= N; i++)
        cout << arr[i] << '\n';
}