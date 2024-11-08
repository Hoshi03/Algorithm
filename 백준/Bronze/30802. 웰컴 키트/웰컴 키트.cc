#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


int main() {
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    int n;
    vector<int> size(6);
    cin >> n;
    for(int i = 0; i < 6; i++) cin >> size[i];
    int shirt, pen;
    cin >> shirt >> pen;
    int a = 0;
    for(int x : size) {
        a += (x + shirt - 1) / shirt;
    }
    cout << a << '\n' << n/pen << " " << n%pen;
    return 0;
}