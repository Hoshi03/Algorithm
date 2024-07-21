#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int n;
    cin >> n;
    while (n-->0){
        string s;
        cin >> s;
        if (s == "push"){
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }

        else if(s == "pop"){
            if (st.empty()) cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }

        else if(s == "size") cout << st.size() << '\n';

        else if(s == "empty") {
            if (st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        else{
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
}