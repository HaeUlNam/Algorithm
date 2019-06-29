#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ttre{
    int age, count;
};

struct info{
    int y, x;
};

int dr[] = {0,0,1,-1,1,1,-1,-1};
int dc[] = {1,-1,0,0,-1,1,-1,1};

int N, M, K;
int A[12][12];
int map[12][12];

vector<vector< vector<ttre> > >  pq(12, vector < vector<ttre> >(12));

void solve()
{
    vector < vector < vector < ttre > > >  temp(12, vector < vector < ttre > >(12));
    vector <info> plustree;

    //봄
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            int End = pq[y][x].size();

            for(int i = 0; i < End; i++)
            {
                int jEnd = pq[y][x][i].count;
                int aa = pq[y][x][i].age;
                int check = true;

                for(int j = 0; j < jEnd; j++)
                {
                    if(aa > map[y][x]) 
                    {
                        check = false;
                        break;    
                    }

                    map[y][x] -= aa;
                    
                }

                map[y][x] -= aa;
                temp[y][x].push_back(aa + 1);
                if((aa + 1) % 5 == 0)
                {
                    info cc = {y,x};
                    plustree.push_back(cc);
                }
            }
        }   
    }

    //여름
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            while(!pq[y][x].empty())
            {
                int aa = pq[y][x].top();
                pq[y][x].pop();
                map[y][x] += aa / 2;
            }

            for(int i = 0; i < temp[y][x].size(); i++)
            {
                pq[y][x].push(temp[y][x][i]);
            }
        }   
    }

    //가을
    for(int i = 0; i < plustree.size(); i++)
    {
        info d = plustree[i];

        for(int j = 0; j < 8; j++)
        {
            int nr = d.y + dr[j];
            int nc = d.x + dc[j];

            if(!(0 < nr && nr <= N && 0 < nc && nc <= N)) continue;
            pq[nr][nc].push(1);
        }
    }

    //겨울
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            map[y][x] += A[y][x];
        }   
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> A[y][x];
            map[y][x] = 5;
        }   
    }

    for(int i = 0; i < M; i++)
    {
        int y, x, age;
        cin >> y >> x >> age;
        bool check = false;
        int End = pq[y][x].size();
        for(int j = 0; j < End; j++)
        {
            ttre bb = pq[y][x][j];
            if(bb.age == age)
            {
                bb.count++;
                check = true;
                break;
            }
        }

        if(!check)
        {
            ttre cc = {age, 1};
            pq[y][x].push_back(cc);
        }
    }

    for(int i = 0; i < K; i++)
        solve();

    int count = 0;
    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            count += pq[y][x].size();
        }
    }

    cout << count << "\n";

    return 0;
}