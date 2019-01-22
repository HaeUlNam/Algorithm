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
  
2. 2차원 배열 시작점 할당

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

<br><br>

### Char형 NULL
-> '\0'

<br>

### # include < stdlib.h  > 에서 필요한 함수
* atoi : String to Integer
* abs  : 절댓값 가져오기