#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m, past = 0, cnt = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> v;
bool isClear = false;

int pos[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int y, int x) {
    visited[y][x] = true;

    if (arr[y][x] == 1) {
        v.push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + pos[i][0];
        int nx = x + pos[i][1];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}

void solution() {
    while (true) {
        visited.clear();
        visited.resize(n, vector<bool>(m, false));
        v.clear();
        dfs(0, 0);

        //dfs를 돌면서 찾은 외곽 1을 0으로 바꿔준다
        for (auto tmp: v) {
            arr[tmp.first][tmp.second] = 0;
        }
        // 외곽 크기로 직전에 녹은 치즈 값을 업데이트
        past = v.size();


        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) flag = true;
            }
        }

        cnt++;
        if (!flag) break;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    solution();
    cout << cnt << '\n' << past;
}