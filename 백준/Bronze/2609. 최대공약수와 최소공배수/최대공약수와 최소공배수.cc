#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int min_num = min(n,m);
    int max_num = max(n,m);

    // 최대공약수
    for(int i = min_num; i > 0; i--){
        if(n % i == 0 && m % i == 0) {
            cout << i << '\n';
            break;
        }
    }
    // 최소공배수

    for(int i = max_num; i <= INT32_MAX; i++){
        if(i % n == 0 && i % m == 0){
            cout << i << '\n';
            break;
        }
    }
}