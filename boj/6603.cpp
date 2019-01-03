/* boj 6603 */
/* Implemented recursively becuase the range of k is up to 13 */

#include<iostream>
using namespace std;

int arr[20];
int k;
void recur(int * aaa, int cur, int count)
{
    if(cur > k) return;
    // cout << cur << " ";   
    if(count >= 6)
    {
        for(int i = 0; i < 6; i++)
        {
            cout << aaa[i] << " ";
        }
        cout << endl;
        return;
    }

    aaa[count] = arr[cur];
    recur(aaa, cur + 1, count + 1);
    aaa[count] = 0;
    recur(aaa, cur + 1, count);
}

int main()
{   
    while(1)
    {
        //input
        cin >> k;
        if(k == 0) break;
        for(int x = 0; x < k ; x++)
            cin >> arr[x];

        int aaa[20];
        recur(aaa, 0, 0);
        cout << endl;

        //init
        for(int i = 0; i < 20; i++)
            arr[i] = 0;
    }
    return 0;
}