#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int res = 0;
    int a1[26] = {};

    for (int i = 0; i < s1.length(); i++) a1[s1[i] - 'a']++;
    for (int i = 0; i < s2.length(); i++) a1[s2[i] - 'a']--;

    for (int i = 0; i < 26; i++) {
        res += abs(a1[i]);
    }

    cout << res;

    return 0;
}
