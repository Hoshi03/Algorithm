#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while(n--> 0){
        stack<char> st;
        string s;
        cin >> s;
        bool isCorrect = true;
        for(char tmp : s){
            if(tmp == '(') st.push(tmp);
            else {
                if(st.empty()) {
                    isCorrect = false;
                    break;
                }
                st.pop();
            }
        }

        if(isCorrect && st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
