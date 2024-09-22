#include <iostream>
#include  "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;

    while (n-->0) {
        string s;
        cin >> s;
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        if (st.empty()) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}