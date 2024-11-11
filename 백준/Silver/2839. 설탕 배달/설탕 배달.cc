#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 3; i <= n; ++i) {
        if (i >= 3 && dp[i - 3] != INT32_MAX) dp[i] = min(dp[i], dp[i - 3] + 1);
        if (i >= 5 && dp[i - 5] != INT32_MAX) dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    if (dp[n] == INT32_MAX) cout << -1;
    else cout << dp[n];
    return 0;
}
