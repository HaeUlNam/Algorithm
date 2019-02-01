#include<iostream>
using namespace std;

int main()
{
    int N = 5;

    int arr[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j < N - i; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;

                for(int k = 0; k < N; k++)
                    cout << arr[k] << ' ';
                cout << endl;
            }
        }
    }

    return 0;
}