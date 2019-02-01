알고리즘 문제 풀 때 Tips.
==========

### # include < functional > greater < T > 사용 차이
- sort 사용할 때, 내림차순

- priority_queue  사용할 때, 오름차순
<br><br>
### 오류가 났을 때, 확인할 것
- 자료형 크기 : long long을 사용해야 하는지 확인.
<br><br>
### map이 2차원이라고, visit도 항상 2차원이어야 한다는 생각 버리자.
-> 상황에 따라서, 3차원, 4차원으로 풀 수도 있다.
<br><br>
### 자릿수를 셀 때 주의할 점.
-> 0은 아래와 같이 자릿수를 셀 때, 한 자리인지 계산하지 못한다.

```cpp
bool checkNum(int & count, const int num)
{
    int tmp = num;
    
    /* 0일때는 count가 안 세어지기에, 1로 설정 */
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

    /* 아래 가지고는 0을 커버하지 못한다. */
    while(tmp != 0)
    {
        int aa = tmp % 10;
        if(arr[aa]) return false;

        tmp /= 10;
        count++;
    }

    return true;
}
```
<br><br>
### STL Vector 사용법
- 생성자로 Vector size을 만들고 시작하려면 아래와 같이 한다.

1. 1차원 배열 할당
```cpp
vector<info> vec(3);
```
|  <center>vec[0]</center> |  <center>vec[1]</center> |  <center>vec[2]</center> |
|:--------|:--------:|--------:|  

```cpp
vector<int> vec = {1,2,3,4};
```
-> 위와 같이 하면, 4개 크기에 각각 숫자로 초기화된다.

2. 2차원 배열 할당

```cpp
vector<info> vec[3]; 
```
-> 이는 인접 리스트와 같은 구조를 만들어 준다.
-> 현재 공간은 할당되어있지 않다.

```cpp
vec[0].push_back(); 
```
-> 위와 같이 해주게 되면, 하나의 공간이 할당된다.  

| vec[0][0] |

```cpp
vector<vector<int>> cctv_start = { {}, {0}, {0,2}, {0,3}, {0,2,3}, {0,1,2,3}};
```
-> 이렇게 하면, 해당하는 숫자 개수만큼 만들어진다.

<br><br>

### Char형 NULL
-> '\0'

<br>

### # include < stdlib.h  > 에서 필요한 함수
* atoi : String to Integer
* abs  : 절댓값 가져오기

### Visit함수
-> copy Visit함수를 통해, 백트래킹 진행할 때 표시를 copy visit에 잘했는지 확인하자.(많이 실수하는 요인 중 하나다.)

### 방향 숫자
-> 방향이 4방향일 때, +1씩 방향을 바꾼다면 %4를 통해 넘어가지 않도록 관리하자.

### x, y 좌표
-> 문제에 x와 y가 각각 x축 이동, y축 이동이라고 명시되어있다면, (y,x) 방식으로 문제를 풀었는지 잘봐야 한다.