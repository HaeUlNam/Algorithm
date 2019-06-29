#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
using namespace std;
bool check[8][8][9];
int dx[] = {0,0,1,-1,1,-1,1,-1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};
int main() {
    int n = 8;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    queue<tuple<int,int,int>> q;
    check[7][0][0] = true;
    q.push(make_tuple(7,0,0));
    bool ans = false;
    while (!q.empty()) {
        int x, y, t;
        tie(x,y,t) = q.front(); q.pop();

        if (x == 0 && y == 7)
        {
            ans = true;
            break;
        }

        for (int k=0; k<9; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nt = min(t+1, 8);   //최대 시간 8초
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (nx-t >= 0 && a[nx-t][ny] == '#')    //벽이 있어서 못가는 경우
                {
                    continue;
                }
                if (nx-t-1 >= 0 && a[nx-t-1][ny] == '#') //벽이 와서 부딪히는 경우
                {
                    continue;
                }            
                if (check[nx][ny][nt] == false) {
                    check[nx][ny][nt] = true;
                    q.push(make_tuple(nx,ny,nt));
                }
            }
        }
    }
    cout << (ans ? 1 : 0) << '\n';
    return 0;
}

