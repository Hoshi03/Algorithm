#include <bits/stdc++.h>
using namespace std;

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    int res = a * b * c;
    int arr[10] = {};
    while (res != 0) {
        int tmp = res % 10;
        arr[tmp]++;
        res /= 10;
    }
    for (int i = 0; i < 10; i++) cout << arr[i] << "\n";
}