#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

bool arr[10];
int Min = INT_MAX;
int N, M;

bool checkNum(int & count, const int i)
{
    int tmp = i;
    
    //0일때는 count가 안 세어지기에, 1로 설정
    if(tmp == 0)
    {
      if(!arr[tmp])
      {
        count = 1;
        return true;
      }
      else
        return false;
    }

    while(tmp != 0)
    {
        int aa = tmp % 10;
        if(arr[aa]) return false;

        tmp /= 10;
        count++;
    }

    return true;
}

int main()
{   
    //Input
    cin >> N >> M;

    int aa;
    for(int i = 0; i < M; i++)
    {
        cin >> aa;
        arr[aa] = 1;
    }

    for(int i = 0; i <= 999900; i++)
    {
        int count = 0;
        
        //해당 버튼을 누를 수 없다면, 계산 X
        if(!checkNum(count, i)) continue;     
        
        int diff;
        diff = abs(N - i) + count;

        if(Min > diff) Min = diff;
    }

    //출발점 100과 비교
    if(Min > abs(N -100))
        Min = abs(N-100);

    cout << Min << endl;

    return 0;
}