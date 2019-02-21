#include<iostream>
using namespace std;

int N;
int arr[1005];

void print()
{
    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort()
{
    for(int i = 0; i < N; i++)
    {
        int idx;
        int smallest = 1001;
        for(int j = i; j < N; j++)
        {
            if(smallest > arr[j])
            {
                smallest = arr[j];
                idx = j;
            }
        }

        Swap(&arr[i], &arr[idx]);
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    SelectionSort();

    for(int i = 0; i < N; i++)
        cout << arr[i] << endl;

    return 0;
}