#include<iostream>
using namespace std;

int map[105][105];
int visit[105][105];

int N, L;
int result;

void solve()
{
    //row 
    for(int row = 0; row < N; row++)
    {   
        int col = 0;
        int nr = row, nc = col;
        for(col = 0; col < N; )
        {
            int nnr = nr, nnc = nc + 1;

            if(0 <= nc && nc < N)
            {
                int diff = map[nr][nc] - map[nnr][nnc];

                if(abs(diff) > 2) break;
                if(diff == 1)
                {
                    if(visit[nnr][nnc]) break;
                    visit[nnr][nnc] = 1;
                    int localvalue = map[nnr][nnc];
                    int localcount = 1;

                    while(1)
                    {
                        nnc++;
                        if((0 < nnc))
                    }
                }
                else if(diff == -1)
                {

                }
            }
            
            col++;
        }
        if(col >= N) result++;
    }

    for(int col = 0; col < N; col++)
    {   
        int row;
        for(row = 0; row < N;)
        {
            
            row++;
        }
        if(row >= N) result++;
    }
}

int main()
{

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    
    solve();

    cout << result << endl;

    return 0;
}