#include<iostream>
#define N 5
using namespace std;

void bubblesort(int n, int arr[]);
void swap(int * a, int * b);

int main()
{
    int arr[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];
    cout << endl;
    bubblesort(N, arr);
    
    for(int k = 0; k < N; k++)
        cout << arr[k] << ' ';

    return 0;
}

/* Ascending Sort */
void bubblesort(int n, int arr[])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j < N - i; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}