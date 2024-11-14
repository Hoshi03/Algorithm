#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n+1,{0,0});
    for(int i = 1; i <=n; i++){
        int tmp;
        cin >> tmp;
        arr[i] ={i,tmp};
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<int> cnt(n + 1, 0);
    int res = 0;

    for(int i = 1; i <= n; i++){
        cnt[i] = cnt[i - 1] + arr[i].second;
        res += cnt[i];
    }

    cout << res;
}
