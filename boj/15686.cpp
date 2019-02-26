#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct info{
    int x, y;
};

int N, M;

vector <info> house;
vector <info> chicken;

int Min = INT_MAX;

int calculate(vector<info> selectC)
{
    int smallest[128];
    for(int i = 0; i < house.size(); i++) 
        smallest[i] = INT_MAX;

    for(int i = 0; i < selectC.size(); i++)
    {
        info aa = selectC[i];

        for(int j = 0; j < house.size(); j++)
        {
            info bb = house[j];
            int diff = abs(aa.x - bb.x) + abs(aa.y - bb.y);

            smallest[j] = min(diff,smallest[j]);
        }
    }

    int sum = 0;
    for(int i = 0; i < house.size(); i++)
    {
        sum += smallest[i];
    }
        
    return sum;
}

void recur(int v, vector<info> selectC)
{
    if(v >= chicken.size())
    {
        if(1 <= selectC.size() && selectC.size() <= M)
        {
            Min = min(calculate(selectC),Min);
        }
        return;
    }

    selectC.push_back(chicken[v]);
    recur(v + 1, selectC);
    selectC.pop_back();
    recur(v + 1, selectC);
}

int main()
{
    cin >> N >> M;

    int input;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> input;
            if(input == 1) house.push_back({i,j});
            else if(input == 2) chicken.push_back({i,j});
        }
    }

    recur(0, vector<info>());

    cout << Min << endl;

    return 0;
}

