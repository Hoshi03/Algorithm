#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<char>> arr;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> people;
vector<vector<int>> fire;
vector<vector<bool>> visited;
pair<int, int> jihun;
vector<pair<int, int>> fires;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    people.resize(n, vector<int>(m, 0));
    fire.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (s[j] == 'J') jihun = {i, j};
            if (s[j] == 'F') fires.push_back({i, j});
        }
    }

    queue<pair<int, int>> q1, q2;
    
    // 지훈 BFS
    q1.push(jihun);
    people[jihun.first][jihun.second] = 1;
    while (!q1.empty()) {
        auto tmp = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int dy = tmp.first + dir[i][0];
            int dx = tmp.second + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= m) continue;
            if (people[dy][dx] != 0 || arr[dy][dx] == '#') continue;
            people[dy][dx] = people[tmp.first][tmp.second] + 1;
            q1.push({dy, dx});
        }
    }

    // 불 BFS
    for (auto x : fires) {
        q2.push(x);
        fire[x.first][x.second] = 1;
    }
    while (!q2.empty()) {
        auto tmp = q2.front();
        q2.pop();
        for (int i = 0; i < 4; i++) {
            int dy = tmp.first + dir[i][0];
            int dx = tmp.second + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= m) continue;
            if (fire[dy][dx] != 0 || arr[dy][dx] == '#') continue;
            fire[dy][dx] = fire[tmp.first][tmp.second] + 1;
            q2.push({dy, dx});
        }
    }

    int res = INT32_MAX;

    // 지훈이 최단거리 기반 BFS
    q1.push(jihun);
    visited[jihun.first][jihun.second] = true;
    while (!q1.empty()) {
        auto tmp = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int dy = tmp.first + dir[i][0];
            int dx = tmp.second + dir[i][1];
            if (dy < 0 || dx < 0 || dy >= n || dx >= m) {
                res = min(res, people[tmp.first][tmp.second]);
                continue;
            }
            if (visited[dy][dx] || arr[dy][dx] == '#') continue;
            if (fire[dy][dx] != 0 && people[tmp.first][tmp.second] + 1 >= fire[dy][dx]) continue;
            visited[dy][dx] = true;
            people[dy][dx] = people[tmp.first][tmp.second] + 1;
            q1.push({dy, dx});
        }
    }

    if (res == INT32_MAX) cout << "IMPOSSIBLE\n";
    else cout << res << "\n";

    return 0;
}
