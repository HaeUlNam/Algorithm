#include<iostream>
using namespace std;

int N;
int A[1000005];
int B, C;
long long totalMan;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;

    /* 총 감독관 무조건(?) 사용 */
    for(int i = 0; i < N; i++)
    {
        A[i] -= B;
        totalMan++;
    }
        
    /* 부 감독관 사용 */
    for(int i = 0; i < N; i++)
    {
        if(A[i] <= 0) continue;
        
        if(A[i] % C > 0)
        {
            totalMan += (A[i] / C) + 1;
        }
        else
        {
            totalMan += (A[i] / C);
        }
    }

    cout << totalMan << endl;

    return 0;
}