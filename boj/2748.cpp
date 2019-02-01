#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    long long Fn_1 = 1;
    long long Fn_2 = 0;
    long long Fn;

    for(int i = 2; i <= N; i++)
    {
        Fn = Fn_1 + Fn_2;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
    }

    if(N >= 2) cout << Fn << endl;
    else if(N == 1) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}