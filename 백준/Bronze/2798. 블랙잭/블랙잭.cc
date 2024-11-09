#include <bits/stdc++.h>

using namespace std;

int n, m, res = 0;
vector<int> arr;
vector<int> tmp;

void dfs(int idx){
    if(tmp.size() == 3){
        int cur = 0;
        for(int x : tmp) cur += x;
        if(cur <= m) res = max(res,cur);
        return;
    }
    for(int i = idx+1; i < arr.size(); i++){
        tmp.push_back(arr[i]);
        dfs(i);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    dfs(-1);
    cout << res;
}