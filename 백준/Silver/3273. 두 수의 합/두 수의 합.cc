#include <bits/stdc++.h>
using namespace std;



int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> map;

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int tmp;
        cin >> tmp;
        map[tmp] = map[tmp]+1;
    }

    int target;
    cin >> target;

    int res = 0;

    for (const auto& pair : map) {
        if (map.find(target - pair.first) != nullptr) {
            res++;
        }
    }

    cout << res/2;
}