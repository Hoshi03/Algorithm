#include <iostream>
#include <bits/stdc++.h>

using namespace std;

static int n;
static vector<vector<int>> arr;
static vector<vector<bool>> visited;
static int pos[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void bfs(int y, int x, int height) {
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x] = true;

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        int dy = tmp.first;
        int dx = tmp.second;
        for (int i = 0; i < 4; i++) {
            y = dy + pos[i][0];
            x = dx + pos[i][1];
            if (y < 0 || x < 0 || y >= n || x >= n) continue;
            if (arr[y][x] <= height || visited[y][x] == true) continue;
            visited[y][x] = true;
            q.push({y,x});
        }
    }
}

void solution(int height, int &cnt) {
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > height && visited[i][j] == false) {
                cnt++;
                bfs(i,j, height);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<bool>(n,false));

    int maxnum = INT32_MIN;

    int cnt = 0, res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            maxnum = max(tmp, maxnum);
        }
    }

    for (int i = 0; i <= maxnum; i++) {
        cnt = 0;
        solution(i, cnt);
        res = max(cnt, res);
    }


    cout << res << '\n';
}