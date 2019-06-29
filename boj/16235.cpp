#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

#define MAX_ROW 15   //input에 따라 바뀜
#define MAX_COL 15   //input에 따라 바뀜

struct info{
    int y,x;
};

//동, 남, 서, 북, 좌측 대각위, 우측 대각위, 좌측 대각아래, 우측 대각아래
int dy[] = {0,1,0,-1,-1,-1,1,1};
int dx[] = {1,0,-1,0,-1,1,-1,1};

int N, M, K;

int yanbun[MAX_ROW][MAX_COL];
int A[MAX_ROW][MAX_COL];
vector< vector < priority_queue < int, vector<int> ,greater<int> > > > vec(MAX_ROW, vector < priority_queue < int, vector<int> ,greater<int> > >(MAX_COL));

int result;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            cin >> A[y][x];
        }
    }

    int x, y, z;
    for(int i = 0; i < M; i++)
    {
        cin >> y >> x >> z;
        vec[y][x].push(z);
    }

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            yanbun[y][x] = 5;
        }
    }

    //K년 동안
    for(int i = 1; i <= K; i++)
    {   
        //봄
        vector<info> fall;

        for(int y = 1; y <= N; y++)
        {
            for(int x = 1; x <= N; x++)
            {
                vector<int> tmp;

                while(!vec[y][x].empty())
                {
                    int a = vec[y][x].top();
                    vec[y][x].pop();

                    int diff = yanbun[y][x] - a;
                    if(diff < 0)
                    {
                        vec[y][x].push(a);
                        break;
                    } 
                    
                    yanbun[y][x] = diff;
                    tmp.push_back(a + 1);
                }
                
                //여름
                while(!vec[y][x].empty())
                {
                    int a = vec[y][x].top();
                    vec[y][x].pop();

                    int divd = a / 2;
                    yanbun[y][x] += divd;
                }

                for(int j = 0; j < tmp.size(); j++)
                {
                    int aa = tmp[j];
                    if((aa % 5) == 0)
                    {
                        info b;
                        b.y = y; b.x = x;
                        fall.push_back(b);                    
                    }

                    vec[y][x].push(aa);
                }
            }   
        }

        //가을
        for(int j = 0; j < fall.size(); j++)
        {
            info a = fall[j];

            for(int k = 0; k < 8; k++)
            {
                int nr = a.y + dy[k];
                int nc = a.x + dx[k];
                
                if(!(0 < nr && nr <= N && 0 < nc && nc <= N)) continue;
                vec[nr][nc].push(1);
            }
        }
        
        //겨울
        for(int y = 1; y <= N; y++)
        {
            for(int x = 1; x <= N; x++)
            {
                yanbun[y][x] += A[y][x];
            }
        }
    }

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
        {
            result += vec[y][x].size();
        }
    }

    cout << result << endl;

    return 0;
}