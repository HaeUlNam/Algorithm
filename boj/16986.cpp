#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int N, K;
int map[12][12];
int visit[10];

vector<int> vec[3];

bool calculate()
{
    int idx[3] = {0};
    int win[3] = {0};
    int c1 = 0, c2 = 1;

    while(idx[0] < N && idx[1] < 20 && idx[2] < 20)
    {
        if(c1 > c2) swap(c1,c2);

        int f = vec[c1][idx[c1]++];
        int s = vec[c2][idx[c2]++];

        int value = map[f][s];
        int next = 3 - c1 - c2;

        if(value == 2) // c1 승리
        {
            win[c1]++;
            c2 = next;
        }
        else // c2 승리
        {
            win[c2]++;
            c1 = next;
        }
        
        if(win[0] >= K) return true;
        if(win[1] >= K) break;
        if(win[2] >= K) break;
    }

    return false;
}

void NexPer(int v)
{   
    if(v >= N)
    {
        if(calculate())
        {
            cout << 1 << "\n";
            exit(0);
        }
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(visit[i]) continue;

        visit[i] = 1;
        vec[0].push_back(i);
        NexPer(v + 1);
        vec[0].pop_back();
        visit[i] = 0;
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    vec[1] = vector<int>(21);
    vec[2] = vector<int>(21);

    for(int i = 0; i < 20; i++)
        cin >> vec[1][i];

    for(int i = 0; i < 20; i++)
        cin >> vec[2][i];

    NexPer(0);
    
    cout << 0 << "\n";
    return 0;
}