#include<iostream>
#include<string>
using namespace std;

int main()
{   
    int score;
    string grade = "FFFFFFDCBAA";

    cin >> score;
    cout << grade[score/10];

    return 0;
}