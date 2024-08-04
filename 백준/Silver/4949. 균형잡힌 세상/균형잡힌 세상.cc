#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true){
        stack<char> st;
        string s;
        getline(cin,s);
        bool isValid = true;
        if (s == ".") break;
        for (char tmp : s) {
            if (tmp == '(' || tmp == '[') st.push(tmp);

            else if (tmp == ')'){
                if (st.empty() || st.top() != '('){
                    isValid = false;
                    break;
                }
                st.pop();
            }

            else if (tmp == ']'){
                if (st.empty() || st.top() != '['){
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) isValid = false;
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}