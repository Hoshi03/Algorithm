#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.emplace(y,x);
    visited[y][x]= 1;

    while (!q.empty()){
        auto tmp = q.front();
        q.pop();
        y = tmp.first;
        x = tmp.second;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
            if (visited[ny][nx] != 0 || arr[ny][nx] == 0) continue;
            q.emplace(ny,nx);
            visited[ny][nx] = visited[y][x]+1;
        }
    }
}

void solution(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((visited[i][j] == 0) && arr[i][j] == 1){
                bfs(i,j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n+1,vector<int>(m+1));
    visited.resize(n+1,vector<int>(m+1,0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }

    solution();
    cout << visited[n][m];
}