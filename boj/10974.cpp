/* boj 10974 */
/* Worst Case Running Time is N! */
/* But N is up to 8, So I implement this problem with recursive */

#include<iostream>
#include<cstdio>
using namespace std;

int N;
int visit[9];
int arr[9];

void recur(int cur, int count)
{
    if(count >= N)
    {
        for(int i = 0; i < count; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(visit[i]) continue;
        
        arr[count] = i;
        visit[i] = 1;
        recur(i, count + 1);
        arr[count] = 0;
        visit[i] = 0;
    }
}
int main()
{
    cin >> N;
    recur(0, 0);

    return 0;
}