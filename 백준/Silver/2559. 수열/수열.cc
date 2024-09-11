#include <iostream>
#include  "bits/stdc++.h"

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i];
    }

    int res = sum;

    for (int i = m; i < n; i++) {
        sum = sum - arr[i-m] + arr[i];
        res = max(res, sum);
    }


    cout << res;
}