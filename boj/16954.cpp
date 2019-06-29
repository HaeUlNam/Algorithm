#include<iostream>
#include<queue>
using namespace std;

#define END_Y 0
#define END_X 7

struct info{
    int y, x;
    int count;
};

int dy[] = {0,0,1,-1,1,1,-1,-1};
int dx[] = {1,-1,0,0,-1,1,-1,1};

bool result = false;
char map[9][9];
int visit_bb[9][9][9];
int visit_uu[9][9];

queue<info> quu;
queue<info> qbb;

void solve()
{
    info start;
    start.y = 7; start.x = 0;  start.count = 0;
    quu.push(start);

    int count = 0;

    while(!quu.empty() || count > 8)
    {
        //욱제 먼저 이동
       while(!quu.empty())
       {
            info a = quu.front();
            //실수 포인트2
            if(count < a.count) break;

            quu.pop();

            //End condition
            if(a.y == END_Y && a.x == END_X)
            {
                result = true;
                return;
            }
            //벽 처리
            if(a.count - 1 >= 0 && visit_bb[a.y][a.x][a.count - 1]) continue;

            //자기 자신 push
            a.count++;
            quu.push(a);

            for(int i = 0; i < 8; i++)
            {
                int nr = a.y + dy[i];
                int nc = a.x + dx[i];

                if(!(0 <= nr && nr < 8 && 0 <= nc && nc < 8)) continue;
                if(visit_uu[nr][nc]) continue;
                if(map[nr][nc] == '#') continue;

                info bb;
                bb.y = nr; bb.x = nc; bb.count = a.count;
                quu.push(bb);
            }
       }

        //벽 그 다음 이동
        while(!qbb.empty())
        {
            info b = qbb.front();
            //실수 포인트2
            if(count < b.count) break;
            
            qbb.pop();

            int nr = b.y + 1;
            int nc = b.x + 0;

            if(!(0 <= nr && nr < 8 && 0 <= nc && nc < 8))
            {
                map[b.y][b.x] = '.';    
                continue;
            }
         
            map[nr][nc] = '#';
            map[b.y][b.x] = '.';
            visit_bb[nr][nc][b.count] = 1;
            
            info dd;
            dd.y = nr; dd.x = nc; dd.count = b.count + 1;
            qbb.push(dd);
        }
        
        count++;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<info> vec;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == '#')
            {
                info aa;
                aa.y = i; aa.x = j; aa.count = 0;
                visit_bb[i][j][0] = 1;
                vec.push_back(aa);
            }
        }
    }

    //실수 포인트1
    for(int i = vec.size() - 1; i >= 0; i--)
        qbb.push(vec[i]);

    solve();

    cout << result << "\n";

    return 0;
}