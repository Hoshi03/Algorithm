#include <bits/stdc++.h>

using namespace std;


bool isPrime(int x){
    if(x == 1) return false;
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, res = 0;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int x : arr) {
        if(isPrime(x)) res++;
    }
    cout << res;
    return 0;
}