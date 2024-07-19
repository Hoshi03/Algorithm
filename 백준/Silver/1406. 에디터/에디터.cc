#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n;
    cin >> n;

    list<char> l;
    for (char x : s) l.push_back(x);
    auto it = l.end();
    while (n-- > 0) {
        char op;
        cin >> op;
        if (op == 'P') {
            char c;
            cin >> c;
            l.insert(it,c);
        }

        else if(op == 'L') {
            if (it != l.begin()) it--;
        }

        else if(op == 'D') {
            if (it != l.end()) it++;
        }

        else if(op == 'B') {
            if (it != l.begin()) {
                it--;
                it = l.erase(it);
            }
        }
    }

    for (char c: l) cout << c;
}
