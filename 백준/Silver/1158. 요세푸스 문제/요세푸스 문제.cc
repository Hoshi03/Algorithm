#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count, tmp = 0;
    cin >> n >> count;

    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= n ; i++) {
        q.push(i);
    }

    while (!q.empty()){
        tmp %= count;
        if (tmp != (count -1)) q.push(q.front());
        else res.push_back(q.front());
        q.pop();
        tmp++;
    }

    cout << '<';
    for (int i = 0; i < res.size()-1; i++) {
        cout << res[i] << ',' << ' ';
    }
    cout << res[res.size()-1] << '>';
}