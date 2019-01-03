#include<iostream>
using namespace std;

int N;
int arr[7];
int visit[10];
/* h e l o w r d*/

bool calculate()
{
    int first = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[2] * 10 + arr[3];
    int second = arr[4] * 10000 + arr[3] * 1000 + arr[5] * 100 + arr[2] * 10 + arr[6];

    if(N == first + second)
    {
        cout << "  " << first << endl;
        cout << "+ " << second << endl;
        cout << "-------" << endl;
        if(N / 100000 == 0) cout << "  ";
        else cout << " ";
        cout << N << endl;
        return true;
    }
    return false;
}

bool recur(int cur, int count)
{
    if(count >= 7)
    {
        if(calculate()) return true;
        return false;
    }

    for(int i = 0; i <= 9; i++)
    {
        if(visit[i]) continue;
        if((cur == 0 || cur == 4) && i == 0) continue;
        
        visit[i] = 1;
        arr[cur] = i;
        if(recur(cur + 1, count + 1)) return true;
        visit[i] = 0;
        arr[cur] = 0;
    }
    return false;
}

int main()
{
    cin >> N;
    
    if(!recur(0,0)) cout << "No Answer" << endl;

    return 0;
}