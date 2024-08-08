#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr(2001);
vector<bool> visited(2001);
bool able = false;

void dfs(int node, int depth){
    // 깊이가 n-1로 생각했는데 실패, 답지보니 깊이가 4인걸 찾는 문제
    if (depth == 4){
        able = true;
        return;
    }

    visited[node] = true;
    for (int i = 0; i < arr[node].size(); ++i) {
        if (!visited[arr[node][i]]){
            dfs(arr[node][i], depth+1);
        }
    }
    visited[node] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    // resize로 푸는 문제가 아님
//    arr.resize(n,vector<int>(n));
//    visited.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i,0);
        if (able) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}