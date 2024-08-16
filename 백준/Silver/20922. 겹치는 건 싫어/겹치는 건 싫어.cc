#include <iostream>
#include "bits/stdc++.h"

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >> n >> m;
    vector<int> arr(n);

    int check[200001] = {0,};
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    int lt = 0, rt = 0, res = 0;
    while (rt < n) {
        if (check[arr[rt]] < m) {
            check[arr[rt]]++;
            rt++;
        }
        else {
            check[arr[lt]]--;
            lt++;
        }
        res = max(res, rt - lt);
    }
    cout << res;
}
