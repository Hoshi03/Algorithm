#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(int cy, int cx, vector<vector<int>>& land, vector<vector<bool>>& visited, int idx, vector<int>& sizes) {
    int length = 0;
    queue<pair<int, int>> q;
    q.emplace(cy, cx);
    visited[cy][cx] = true;
    land[cy][cx] = idx;  // 덩어리 인덱스로 표시

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        length++;

        for (int i = 0; i < 4; i++) {
            int ny = tmp.first + dy[i];
            int nx = tmp.second + dx[i];

            if (ny >= 0 && ny < land.size() && nx >= 0 && nx < land[0].size()
                && !visited[ny][nx] && land[ny][nx] == 1) {
                q.emplace(ny, nx);
                visited[ny][nx] = true;
                land[ny][nx] = idx;  // 덩어리 인덱스로 표시
            }
        }
    }

    sizes.push_back(length);  // 해당 인덩어리의 크기 저장
    return length;
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> sizes;  // 각 덩어리 크기 저장
    int idx = 2;  // 덩어리 번호는 2부터 시작

    // 전체 land를 한번 순회하며 각 석유 덩어리의 크기를 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, land, visited, idx++, sizes);
            }
        }
    }

    int answer = 0;

    // 각 열에 대해 석유량 계산
    for (int i = 0; i < m; i++) {
        unordered_set<int> seen;
        int res = 0;

        for (int j = 0; j < n; j++) {
            if (land[j][i] >= 2 && seen.find(land[j][i]) == seen.end()) {
                res += sizes[land[j][i] - 2];
                seen.insert(land[j][i]);
            }
        }

        answer = max(answer, res);
    }

    return answer;
}


