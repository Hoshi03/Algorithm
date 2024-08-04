#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0, s= 1, maxS = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int posX[] = {0,1,0,-1};
int posY[] = {1,0,-1,0};
queue<pair<int,int>> q;

void bfs(int y, int x){
    q.emplace(y,x);
    visited[y][x] = true;
    s = 1;
    while (!q.empty()){
        auto tmp = q.front();
        y= tmp.first;
        x = tmp.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = y + posY[i];
            int dx = x + posX[i];
            if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
            if (visited[dy][dx] || arr[dy][dx] == 0) continue;
            q.emplace(dy,dx);
            visited[dy][dx] = true;
            s++;
        }
    }
}

void solution(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == 1){
                res++;
                bfs(i,j);
                maxS = max(s, maxS);
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; //n 세로 m 가로

    arr.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    solution();

    int maa = 0;

    cout << res <<'\n';
    cout << maxS << '\n';
}