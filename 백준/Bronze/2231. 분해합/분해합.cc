#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool isFind = false;

    for(int i = 1; i <= 1000000; i++){
        int tmp = 0;
        int sub = 0;
        int idx = 1;
        int cur = i;
        while (cur != 0){
            tmp = tmp + (cur % 10) * idx;
            sub = sub + cur % 10;
            cur /= 10;
            idx *= 10;
        }
        if (sub + tmp == n) {
            cout << tmp;
            isFind = true;
            break;
        }
    }

    if(!isFind) cout << 0;
}