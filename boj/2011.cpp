#include<iostream>
#include<string>
using namespace std;

int main()
{
    int dp[5002] = {0};
    string input;
    cin >> input;

    int N = input.size();

    if(input[0] != '0') dp[0] = 1;
    if(input[1] != '0') dp[1] = 1;

    int comp = int(input[0] - '0') * 10 + int(input[1] - '0');
    if(10 <= comp && comp <= 26) dp[1] += 1;

    for(int i = 2; i < N; i++)
    {
        //one
        if(input[i] != '0') dp[i] = dp[i-1]%1000000;

        //two
        comp = int(input[i-1] - '0') * 10 + int(input[i] - '0'); 
        if(10 <= comp && comp <= 26) dp[i] += dp[i-2] % 1000000;
    }

    cout << dp[N-1]%1000000 << endl;
    
    return 0;
}