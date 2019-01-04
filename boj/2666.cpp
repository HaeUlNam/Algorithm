/*  This problem does not apply [Greedy algorithm]
    It can be influenced by current point but also next point */


/*  I solved problem by [brute force] with a little rule. 
    
    I use Partial Greedy Choice. 
    We can prove that it is better to move Y before X.

    example) X b Y c
    - X Y is given value.
    - first time we have to visit point c.
    - second time.. point b. 

    prove) <case 1 : b >=(x+c)/2>
                when Y -> c, (c - y) + (c - b)
                when X -> c, (c - x) + (y - b)

           <case 2 : b < (x+c)/2>
                when Y -> c, (c - y) + (b - x)
                when X -> c, (c - x) + (y - b)

        Finally,
        ** For cases 1 and 2, 
        ** the value of distance is smaller when Y moves first.
*/

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int N;
int Min = INT_MAX;
int length;

int arr[21];

void solve(int idx, int left, int right, int count)
{
    /* End Condition */
    if(idx >= length)
    {
        Min = min(count, Min);
        return;
    }

    if(arr[idx] <= left)
    {
        int diff = left - arr[idx];
        solve(idx + 1, left - diff, right, count + diff);
    }
    else if(right <= arr[idx])
    {
        int diff = arr[idx] - right;
        solve(idx + 1, left, right + diff, count + diff);
    }
    else
    {
        /* left select */ 
        int ldiff = arr[idx] - left;
        solve(idx + 1, left + ldiff, right, count + ldiff);

        /* right select */
        int rdiff = right - arr[idx];
        solve(idx + 1, left, right - rdiff, count + rdiff);
    }
}

int main()
{
    int left, right;
    cin >> N >> left >> right >> length;

    for(int i = 0; i < length; i++)
        cin >> arr[i];
    
    solve(0, left, right, 0);
    cout << Min << endl;

    return 0;
}