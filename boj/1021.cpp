#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int N, M;

vector<int> order;
int visit[55];

int result;

int main()
{
    order.push_back(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        order.push_back(i);

    int input;
    int localN = N;

    for(int i = 0; i < M; i++)
    {   
        cin >> input;
        
        int local = order[input];
        
        int left = abs(local - 1);
        int right = abs(localN - local + 1);

        if(left < right)
        {
            for(int i = 1; i <= N; i++)
            {
                if(visit[i]) continue;
                order[i] = order[i] - left;
                if(order[i] <= 0)
                    order[i] += localN;   
            }
            result += left;
        }
        else
        {
            for(int i = 1; i <= N; i++)
            {
                if(visit[i]) continue;

                order[i] = (order[i] + right);
                if(order[i] > localN)
                    order[i] %= localN;
            }
            result += right;
        }

        //첫번째꺼 빼준다.
        localN--;
        visit[input] = 1;
        order[input] = -1;
        for(int i = 1; i <= N; i++)
        {
            if(visit[i]) continue;
            order[i]--;
        }
    }

    cout << result << endl;

    return 0;
}