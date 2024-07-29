#include <iostream>
#include <bits/stdc++.h>
#include <deque>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> q;
    int n;
    cin >> n;
    for (int i = n; i >= 1 ; i--) {
        q.push_front(i);
    }

    int tmp = 1;
    while (q.size() != 1){
        tmp %= 2;
        if (tmp == 1) {
            q.pop_front();
            tmp++;
        }

        else if (tmp == 0){
            int pre = q.front();
            q.pop_front();
            q.push_back(pre);
            tmp++;
        }
    }

    cout << q.front();
}