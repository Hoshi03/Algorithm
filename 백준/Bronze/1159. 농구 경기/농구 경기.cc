#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[26] = {0,};
    bool sun = false;
    while (n --> 0){
        string s;
        cin >> s;
        arr[s[0] - 97]++;
    }

    string res = "";
    for (int i = 0; i < 26; i++) {
        if (arr[i] >= 5) {
            res += (char)(i+97);
            sun = true;
        }
    }

    if (!sun) cout << "PREDAJA";
    else cout << res;
}