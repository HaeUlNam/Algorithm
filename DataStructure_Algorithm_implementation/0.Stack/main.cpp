#include "stack.h"

void Print(stack<int> &s)
{
    //Push
    for(int i = 0; i < 5; i++)
    {
        cout << "Stack Size : " << s.size() << " ";
        int * arr = s.getarr();
        cout << "Stack Data : ";
        for(int j = 0; j < s.size(); j++)
            cout << arr[j] << " ";

        cout << endl << "----------------------------------" << endl;

        s.push(i);
    }

    //Pop
    for(int i = 0; i < 6; i++)
    {
        cout << "Stack Size : " << s.size() << " ";
        int * arr = s.getarr();
        cout << "Stack Data : ";
        for(int j = 0; j < s.size(); j++)
            cout << arr[j] << " ";
        
        cout << endl << "----------------------------------" << endl;

        s.pop();
    }
}

int main()
{
    stack <int> s;

    //stack push() pop() flow를 보기 위한 함수
    Print(s);

    return 0;
}