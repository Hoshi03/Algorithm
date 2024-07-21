#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max = 0, cnt = 1;
    cin >> n;

    stack<int> st;
    string res = "";

    while (n --> 0){
        int tmp = 0;
        cin >> tmp;
        while (cnt <= tmp){
            st.push(cnt++);
            res.append("+\n");
        }

        if (tmp != st.top() || st.empty()) {
            res = "NO";
            break;
        }

        else{
            st.pop();
            res.append("-\n");
        }
    }

    cout << res;
}