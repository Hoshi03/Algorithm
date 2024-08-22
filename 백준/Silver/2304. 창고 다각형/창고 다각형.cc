#include <iostream>
#include  "bits/stdc++.h"

using namespace std;


int main()
{
    int max_pos = 0, max_height = 0;
    int res = 0;
    int arr[1001] = {0,};
    int pos, height, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pos >> height;
        arr[pos] = height;
        if (max_height < height)
        {
            max_pos = pos;
            max_height = height;
        }
    }

    int lt=0;
    for (int i = 1; i <max_pos; i++)
    {
        lt = max(lt, arr[i]);
        res += lt;
    }

    int rt=0;
    for (int i = 1000; i > max_pos; i--)
    {
        rt = max(rt, arr[i]);
        res += rt;
    }

    cout << res + max_height;

}