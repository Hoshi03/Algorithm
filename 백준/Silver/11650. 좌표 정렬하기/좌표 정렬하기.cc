#include <bits/stdc++.h>
using namespace std;

bool sorting(pair<int, int> x1, pair<int, int> x2){
    if(x1.first == x2.first){
        return x1.second < x2.second;
    }

    return x1.first < x2.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr.begin(), arr.end(), sorting);

    string s = "";
    for(auto x : arr) {
        s += to_string(x.first); s += " "; s+= to_string(x.second); s+=  '\n';
    }
    cout << s;
}

