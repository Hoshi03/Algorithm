#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0;
    cin >> n;

    stack<int> st;

    while (n --> 0){
        int tmp;
        cin >> tmp;
        if (tmp == 0) st.pop();
        else st.push(tmp);
    }

    while (!st.empty()){
        res += st.top();
        st.pop();
    }

    cout << res;
}