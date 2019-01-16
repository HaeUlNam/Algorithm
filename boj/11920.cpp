#include<iostream>
#include<functional>
#include<queue>
using namespace std;

int main()
{
    int N, K;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    priority_queue < long long, vector < long long >, greater < long long > > q;

    for(int i = 0; i < N; i++)
    {
        long long aa;
        cin >> aa;
        q.push(aa);

        //Window Size K
        if(i < K) continue;

        cout << q.top() << ' ';
        q.pop();
    }

    //남은 K개
    for(int i = 0; i < K; i++)
    {
        cout << q.top() << ' ';
        q.pop();
    }

    return 0;
}
