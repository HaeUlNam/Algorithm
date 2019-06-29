#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct info{
    int y, x;
    int num;
};

int map[11][11];
int Min = INT_MAX;

vector<info> vec;
vector<info> bblock;

int block[6] = {0,5,5,5,5,5};
int blocknum[6] = {0,1,4,9,16,25};


void print()
{
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            cout << map[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(int v)
{
    if(v >= vec.size())
    {
        bool check = true;
        for(int y = 0; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                if(map[y][x])
                {
                    check = false;
                    break;
                }
            }
        }

        if(check)
        {
            int llocal = bblock.size();
            Min = min(Min, llocal);
        }
        return;
    }

    info a = vec[v];

    if(!map[a.y][a.x])
    {
        solve(v + 1);
    }
    else
    {
        for(int i = 1; i <= 5; i++)
        {
            if(block[i] == 0) continue;
            
            int yend = a.y + i;
            int xend = a.x + i;
            int count = 0;

            for(int y = a.y; y < yend; y++)
            {
                for(int x = a.x; x < xend; x++)
                {
                    if(map[y][x])
                    {
                        // cout << map[y][x] << " ";
                        count++;
                    } 
                }
            }
            // cout << endl;

            // cout << v << "/" << i << "/" << count << "\n";

            if(count == blocknum[i])
            {
                for(int y = a.y; y < yend; y++)
                {
                    for(int x = a.x; x < xend; x++)
                    {
                        map[y][x] = 0;
                    }
                }

                info cc = {a.y, a.x, i};
                bblock.push_back(cc);
                block[i]--;
                // print();
                solve(v + 1);
                bblock.pop_back();
                block[i]++;

                for(int y = a.y; y < yend; y++)
                {
                    for(int x = a.x; x < xend; x++)
                    {
                        map[y][x] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            cin >> map[y][x];   
            if(map[y][x])
            {
                info a = {y, x, 0};
                vec.push_back(a);
            }
        }   
    }

    for(int y = 0; y < 15; y++)
    {
        for(int x = 0; x < 15; x++)
        {
            cout << map[y][x] << " ";   
        }
        cout << "\n";
    }

    // solve(0);

    if(Min == INT_MAX) cout << -1 << "\n";
    else cout << Min << "\n";

    return 0;
}