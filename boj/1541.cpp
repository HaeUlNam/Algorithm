#include<iostream>
#include<cstdlib> //atoi
using namespace std;

int main()
{
    char input[51];
    int total = 0;

    //If true, There is at least one minus.
    bool oper = false;

    cin >> input;
    for(int i = 0; ;i++)
    {
        char num[6];
        int numCount = 0;
        while(input[i]!= '\0' && input[i] != '-' && input[i] != '+')
            num[numCount++] = input[i++];
        num[numCount] = '\0';

        if(!oper) total += atoi(num); 
        else total -= atoi(num);

        if(input[i] == '\0') break;
        else if(input[i] == '-') oper = true;
    }

    cout << total << endl;

    return 0;
}