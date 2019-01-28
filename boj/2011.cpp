#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    int arr[5005][2] = {0};
    string input;
    cin >> input;

    int N = input.size();

    //base condition
    if(input[0] != '0') arr[0][0] = 1;
    arr[0][1] = 0;

    if(input[1] != '0') arr[1][0] = arr[0][0] + arr[0][1];

    char compare[3] = {input[0],input[1],'\0'};
    if(1 <= atoi(compare) && atoi(compare) <= 26) arr[1][1] = 1;
    else arr[1][1] = 0;

    for(int i = 2;  i < N; i++)
    {
        //A[i][0]
        if(input[i] != '0') arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % 1000000;

        //A[i][1]
        char compare[3] = {input[i-1],input[i],'\0'};

        if(int(input[i] - '0') == atoi(compare)) continue;
        
        if(1 <= atoi(compare) && atoi(compare) <= 26) arr[i][1] = (arr[i-2][0] + arr[i-2][1]) % 1000000;
        else arr[i][1] = 0;
    }

    cout << (arr[N-1][0] + arr[N-1][1]) % 1000000<< endl;

    return 0;
}