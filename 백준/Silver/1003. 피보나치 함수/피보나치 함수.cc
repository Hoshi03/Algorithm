#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    pair<int,int> arr[41];
    arr[0] = {1,0};
    arr[1] = {0,1};
    for(int i = 2; i <= 40; i++){
        arr[i] = {(arr[i-1].first + arr[i-2].first),(arr[i-1].second + arr[i-2].second)};
    }

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cout << arr[tmp].first << " " << arr[tmp].second << '\n';
    }
}
