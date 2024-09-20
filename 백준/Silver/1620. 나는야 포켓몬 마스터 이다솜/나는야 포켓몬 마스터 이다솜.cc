#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    cin >> m;

    string tmp;
    unordered_map<int, string> imap;
    unordered_map<string, int> smap;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        imap[i] = tmp;
        smap[tmp] = i+1;
    }

    for (int i = 0; i < m; i++) {
        cin >> tmp;

        if (tmp[0] < 65){
            cout << imap[stoi(tmp)-1] << '\n';
        }

        else{
            cout << smap[tmp] << '\n';
        }
    }
}
