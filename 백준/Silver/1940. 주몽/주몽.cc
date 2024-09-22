//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int res = 0;

    int lt = 0, rt = n-1;
    sort(arr.begin(), arr.end());
    while (lt < rt){
        int hap = arr[lt] + arr[rt];
        if (hap == m) {
            res++;
            lt++;
            rt--;
        }

        else if(hap < m) lt++;
        else if(hap > m)rt--;
    }

    cout << res;

    return 0;
}
