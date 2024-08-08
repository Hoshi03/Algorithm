#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int x, y;
vector<vector<int>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs() {
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = tmp.first + dy[i];
            int nx = tmp.second + dx[i];
            if (ny < 0 || nx < 0 || nx >= x || ny >= y) continue;
            if (arr[ny][nx] == -1 || visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[tmp.first][tmp.second] + 1;
            arr[ny][nx] = 1;
            q.emplace(ny, nx);
        }
    }
}

void solution() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (arr[i][j] == 1) {
                q.emplace(i, j);
                visited[i][j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    arr.resize(y, vector<int>(x));
    visited.resize(y, vector<int>(x, 0));

    bool yammy = true;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int tmp;
            cin >> tmp;
            if (yammy && tmp == 0) yammy = false;
            arr[i][j] = tmp;
        }
    }

    if (yammy) {
        cout << 0;
        return 0;
    }

    solution();
    bfs();

    int max1 = 0;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max1 = max(max1, visited[i][j]);
        }
    }

    cout << max1 - 1;
}