//Quick Selction
//Randomized Selection & Deterministic Selection

#include<iostream>
#include<ctime>
using namespace std;

int arr[5000001];

void swap_(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//중간 idx 반환
int Partition(int start, int end)
{
    int diff = (end - start) + 1;
    int pivot = rand() % diff;
    swap(arr[start], arr[start + pivot]);
    
    int i = start, j = start + 1;

    while(j <= end)
    {
        if(arr[j] < arr[start])
        {
            ++i;
            swap(arr[j], arr[i]);   
        }
        j++;
    }

    swap(arr[start], arr[i]);

    return i;  
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    srand((unsigned)time(NULL));

    int N, K;
    cin >> N >> K;
    K--;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = N - 1;
    int result = arr[start];

    while(start <= end)
    {
        int pIdx = Partition(start, end);

        if(pIdx == K)
        {
            result = arr[pIdx];
            break;
        }
        else if(pIdx > K)
        {
            end = pIdx - 1;
        }
        else
        {
            start = pIdx + 1;
        }
    }
    
    cout << result << "\n";

    return 0;
}