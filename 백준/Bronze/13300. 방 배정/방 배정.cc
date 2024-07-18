#include <bits/stdc++.h>
using namespace std;



int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, max = 0, res = 0;
    cin >> n >> max;
    int arr[7][2] = {};
    for (int i = 0; i < n; i++) {
        int s, g;
        cin >> s >> g;
        arr[g][s]++;
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            int tmp = arr[i][j]% max;
            if (tmp != 0) res++;
            res += arr[i][j]/2;
        }
    }

    cout << res;
}