#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    int ppow = 1;

    for(int i = 0; i < n; i++){
        int tmp = s[i] - 96;
        res += tmp * ppow;
        ppow *= 31;
    }
    cout << res;
}