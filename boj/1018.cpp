#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

char map[51][51];
int N, M;

char cc[2] = {'W','B'};

int Min = INT_MAX;

int main()
{
    cin >> N >> M;

    //입력
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    //모든 map 탐색
    for(int i = 0; i <= N - 8; i++)
    {
        for(int j = 0; j <= M - 8; j++)
        {
            int count1 = 0, count2 = 0;
            int c1 = 0, c2 = 1; 

            //8 * 8
            for(int y = i; y <= i + 7; y++)
            {
                for(int x = j; x <= j + 7; x++)
                {
                    if(map[y][x] != cc[c1])
                    {
                        count1++;
                    }
                    if(map[y][x] != cc[c2])
                    {
                        count2++;
                    }

                    c1 = (c1 + 1) % 2;
                    c2 = (c2 + 1) % 2;
                }

                //한번 더 switch
                c1 = (c1 + 1) % 2;
                c2 = (c2 + 1) % 2;
            }
            
            //최소값 비교
            Min = min(Min, min(count1, count2));
        }
    }

    cout << Min << endl;

    return 0;
}