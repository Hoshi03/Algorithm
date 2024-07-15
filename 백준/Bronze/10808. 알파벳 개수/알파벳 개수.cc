#include <bits/stdc++.h>
using namespace std;



int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int alphabet[30] ={};
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        alphabet[s[i]-97]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
}