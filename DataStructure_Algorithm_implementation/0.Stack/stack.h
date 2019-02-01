#include<iostream>
#define N 4

using namespace std;

template <typename T>
class stack{
private:
    int capacity;   //전체 배열 크기
    int SSize;       //데이터가 들어있는 개수
    T Top;        //가장 위에 있는 데이터
    T * arr;
public:
    stack(int theCapacity = N)
    {
        arr  = new T[N];
        SSize = 0;
        capacity = theCapacity;
    }
    ~stack()
    {
        delete[] arr;
    }

    void ChangeSize(int * &arr, int oldCapacity, int newCapacity)
    {
        int * temp = new T[newCapacity];
        for(int i = 0; i < SSize; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
    }

    void push(T data)
    {
        if(SSize == capacity)
        {
            ChangeSize(arr, capacity, 2 * capacity);
            capacity *= 2;
        }
        arr[SSize++] = data;
        Top = data;
    }
    
    void pop()
    {
        if(SSize > 0) 
        {
            arr[SSize--] = 0;
            Top = arr[SSize];
        }
        else
            cout << "There is no data in Stack" << endl;
    }

    T top()
    {
        if(SSize > 0) 
            return Top;
        else
            cout << "There is no data in Stack" << endl;
    }

    int empty()
    {
        if(SSize == 0) return 1;
        return 0;
    }

    int size()
    {
        return SSize;
    }

    T * getarr()
    {
        return arr;
    }
};