#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main() {
    string s;
    cin >> s;
    string res = s;
    reverse(s.begin(), s.end());
    if (res == s)cout << 1;
    else cout << 0 ;

}