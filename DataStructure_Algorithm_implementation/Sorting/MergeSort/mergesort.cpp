//boj 2751번 같이 품

#include<iostream>
using namespace std;

int N;
int arr[1000005];
int * localArr;

void MergeSort(int start, int end)
{
    //T(1) return
    if(start >= end) return; 

    int middle = (start + end) / 2;

    //반반 split
    MergeSort(start, middle);   
    MergeSort(middle + 1, end);

    int initN = (end - start) + 1;  

    int fList = start;
    int sList = middle + 1;
    int count = start;

    //Merge
    while(fList <= middle && sList <= end)
    {
        if(arr[fList] > arr[sList])
            localArr[count++] = arr[sList++];
        else
            localArr[count++] = arr[fList++];
    }

    if(fList > middle)
    {
        while(sList <= end)
            localArr[count++] = arr[sList++];
    }
    else
    {
        while(fList <= middle)
            localArr[count++] = arr[fList++];
    }

    //복사
    for(int i = start; i <= end; i++)
        arr[i] = localArr[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    localArr = new int[N + 5];

    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    MergeSort(1, N);

    for(int i = 1; i <= N; i++)
        cout << arr[i] << '\n';

    delete[] localArr;

    return 0;
}