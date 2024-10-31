#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int>> arr;
vector<bool> visited;
vector<pair<int, int>> res;
int max_val = -1;
int tmp = 0;


void dfs(int start) {
    tmp++;
    visited[start] = true;
    for (int x: arr[start]) {
        if (!visited[x]) dfs(x);
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        visited.clear();
        visited.resize(n + 1, false);
        dfs(i);
        max_val = max(max_val, tmp);
        res.push_back({i, tmp});
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    arr.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
//        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    solution();
    sort(res.begin(), res.end());

    for(auto x : res){
        if(x.second == max_val) cout << x.first << " ";
//        cout << x.first << " " << x.second << '\n';
    }


    return 0;
}
