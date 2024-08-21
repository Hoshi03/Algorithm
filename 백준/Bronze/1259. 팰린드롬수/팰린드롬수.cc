#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {
    while (true){
        int tmp;
        cin >> tmp;
        if (tmp == 0 ) return 0;
        int pal = tmp;
        int cmp = 0;
        while (pal != 0){
            cmp = cmp * 10 + pal %10;
            pal /= 10;
        }
        if (tmp == cmp) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}