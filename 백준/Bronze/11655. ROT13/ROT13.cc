#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<int> arr;

    for (char i : s) {
        arr.push_back(i);
    }

    for (int &x : arr) {
        if (x >= 65 && x < 97) {
            x += 13;
            if (x > 90) x -= 26;
        }
        else if (x >= 97 && x <= 122) {
            x += 13;
            if (x > 122) x -= 26;
        }
    }


    for (char x : arr) cout << x;

    return 0;
}
