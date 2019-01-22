#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

struct info{
    long long startidx, endidx;
    long long sum;
};

long long N;

long long num[10];
char operater[10];

long long Max = LONG_MIN;

long long calculate(long long left, long long right, char oper)
{
    if(oper == '+') return left + right;
    else if(oper == '-') return left - right;
    else if(oper == '*') return left * right;

    return 0;
}


void recur(long long cur, long long idx, long long sum, vector<info> vec)
{
    if(cur > N / 2)
    {
        if(idx != -1)
            vec.push_back({idx, cur - 1, sum});        

        long long localTotal = vec[0].sum;

        for(long long i = 1; i < vec.size(); i++)
            localTotal = calculate(localTotal, vec[i].sum, operater[vec[i-1].endidx]);

        if(Max < localTotal) 
            Max = localTotal;

        return;
    }

    //Open Bracket
    if(idx == -1)
    {
        idx = cur;
        sum = num[cur];

        //Still Open Bracket
        recur(cur + 1, idx, sum ,vec);

        //Close Bracket
        vec.push_back({idx, cur, sum});
        recur(cur + 1, -1, 0, vec);
        vec.pop_back();
    }
    //Close Bracket
    else
    {
        sum = calculate(sum, num[cur], operater[cur - 1]);

        vec.push_back({idx, cur, sum});
        recur(cur + 1, -1, 0, vec);
        vec.pop_back();
    }
}

int main()
{
    cin >> N;
    char aa[21];
    cin >> aa;
    
    long long count = 0;
    for(long long i = 0; i < N / 2; i++)
    {
        num[i] = aa[count++] - '0';
        operater[i] = aa[count++];
    }
    num[N / 2] = aa[count] - '0';

    recur(0,-1, 0, vector<info>());

    cout << Max << endl;

    return 0;
}