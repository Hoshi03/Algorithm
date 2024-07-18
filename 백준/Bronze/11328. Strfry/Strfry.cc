#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        int arr[26] = {};
        string s1, s2;
        cin >> s1 >> s2;
        for (char c : s1) arr[c - 'a']++;
        for (char c : s2) arr[c - 'a']--;

        bool is_possible = true;
        for (int j = 0; j < 26; j++) {
            if (arr[j] != 0) {
                is_possible = false;
                break;
            }
        }
        res[cnt] = is_possible ? 0 : 1;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == 0) cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";
    }

    return 0;
}
