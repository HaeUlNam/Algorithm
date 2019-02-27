#include<iostream>
#include<vector>
using namespace std;

struct info{
    int y, x;
};

//남, 서, 북, 동
int dr[] = {1,0,-1,0};
int dc[] = {0,-1,0,1};

char map[13][7];
int visit[13][7];

vector<info> puyo;  //현재 값을 가지는 모든 푸요들
vector<info> spuyo; //같은 색을 가진 푸요들 저장하기 위해..

int result = 0;

void init()
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            visit[i][j] = 0;
        }
    }

    spuyo.clear();
}

void dfs(int v, info a, char color)
{
    visit[a.y][a.x] = 1;
    spuyo.push_back(a);

    for(int i = 0; i < 4; i++)
    {
        int nr = dr[i] + a.y;
        int nc = dc[i] + a.x;

        if(!(0 <= nr && nr < 12 && 0 <= nc && nc < 6)) continue;
        if(map[nr][nc] != color) continue;
        if(visit[nr][nc] == 1) continue;

        dfs(v + 1, {nr,nc}, color);
    }
}

int main()
{
    for(int y = 0; y < 12; y++)
    {
        for(int x = 0; x < 6; x++)
        {
            cin >> map[y][x];
            if(map[y][x] != '.')
                puyo.push_back({y,x});
        }
    }

    bool check = true;

    while(check)
    {
        check = false;

        for(int i = 0; i < puyo.size(); i++)
        {
            info a = puyo[i];

            //dfs를 통해, 같이 삭제된 경우..
            if(map[a.y][a.x] == '.') continue;
            
            dfs(0, a, map[a.y][a.x]);
            
            if(spuyo.size() >= 4)
            {
                check = true;

                for(int j = 0; j < spuyo.size(); j++)
                {
                    info b = spuyo[j];
                    map[b.y][b.x] = '.';
                }
            }

            init();
        }

        //puyo를 한번 돌면서, map에 '.'된 거는 뺀다.
        vector<info> tmp;

        for(int a = 0; a < puyo.size(); a++)
        {
            info b = puyo[a];

            if(map[b.y][b.x] == '.') continue;
            tmp.push_back(b);
        }
        puyo.clear();
        puyo = tmp;

        //아래로 내리는 작업을 한다.
        for(int a = puyo.size() - 1; a >= 0; a--)
        {
            info b = puyo[a];

            while(1)
            {
                int nr = dr[0] + b.y;
                int nc = dc[0] + b.x;

                if(!(0 <= nr && nr < 12 && 0 <= nc && nc < 6)) break;
                if(map[nr][nc] != '.') break;

                map[nr][nc] = map[b.y][b.x];
                map[b.y][b.x] = '.';
                b.y = nr; b.x = nc;
            }
            puyo[a] = b;
        }

        if(check) result++;
    }

    cout << result << endl;

    return 0;
}

/*
* 삼성 역량 테스트 시험 전 작성해할 것.

-> 라이브러리 (iostream, vector, queue, stack, cstdlib, string, climits, algorithm)
-> 방향 벡터 (동, 남, 서, 북) 
-> 디버깅용 코드
*/