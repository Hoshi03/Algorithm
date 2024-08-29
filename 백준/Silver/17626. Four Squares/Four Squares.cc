#include <iostream>
#include  "bits/stdc++.h"

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    // int i = 1;
    // while (i * i <= 50000) {
    //     pow.push_back(i*i);
    //     i++;
    // }

    // //무조건 합이 나옴
    // for (int i = 225; i >= 1 && n != 0; i--) {
    //     if (n >= pow[i]) {
    //         n -= pow[i];
    //         cnt++;
    //     }
    // }

    for (int i = 1; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    cout << dp[n] << '\n';
}