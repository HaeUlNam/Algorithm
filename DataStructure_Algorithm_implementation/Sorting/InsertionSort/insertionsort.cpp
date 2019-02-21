#include<iostream>
using namespace std;

int N;
int arr[1005];

void InsertionSort()
{
    for(int i = 1; i < N; i++)
    {   
        int tmp = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(tmp >= arr[j]) break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    InsertionSort();

    for(int i = 0; i < N; i++)
        cout << arr[i] << endl;

    return 0;
}