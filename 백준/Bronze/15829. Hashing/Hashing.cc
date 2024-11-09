#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    string s;
    cin >> n >> s;
    long long res = 0;
    long long ppow = 1;

    for(int i = 0; i < n; i++){
        int tmp = s[i] - 96;
        res = (res + (tmp * ppow)) % 1234567891;
        ppow = (ppow * 31) % 1234567891;
    }
    cout << res;
}