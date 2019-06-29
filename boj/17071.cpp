#include<iostream>
#include<queue>
using namespace std;

struct info{
    int idx, zm;
};

int didx[3] = {-1, 1, 0};

int d[500005][2]; /* 0이면 짝수, 1이면 홀수 */
int N, K;

queue<info> q;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for(int i = 0; i <= 500000; i++)
    {
        d[i][0] = -1;
        d[i][1] = -1;
    }

    d[N][0] = 0;    //0초라는 뜻
    q.push({N, 0});

    /*
    이렇게 BFS를 돌리게 되면, d배열 모든 곳에 짝수로 방문할 때와 홀수로 방문할 때의 초가 기록되게 된다.
    2배를 하게 되면, 홀수가 짝수로 짝수가 홀수로 바뀌기에.. 모든 곳에 값이 적힘.
    */
    while(!q.empty())
    {
        info a = q.front();
        q.pop();

        didx[2] = a.idx;

        for(int i = 0; i < 3; i++)
        {
            int nidx = a.idx + didx[i];

            if(!(0 <= nidx && nidx <= 500000)) continue;
            if(d[nidx][1 - a.zm] != -1) continue;

            d[nidx][1 - a.zm] = d[a.idx][a.zm] + 1;
            q.push({nidx, 1 - a.zm});
        }
    }

    int result = -1;
    for(int i = 0; i < 500000; i++)
    {
        K += i;
        if(K > 500000) break;

        /* i보다 작다면 만날 수 없다. 동생은 계속 앞으로 나가기에.. */
        if(d[K][i % 2] <= i)
        {
            result = i;
            break;
        }
    }

    cout << result << "\n";

    return 0;
}