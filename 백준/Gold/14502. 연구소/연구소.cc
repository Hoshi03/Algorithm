#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int pos[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int n, m, res = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> plane;

void bfs(vector<vector<int>> &board, int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    visited[i][j] = true;


    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        int dy = tmp.first;
        int dx = tmp.second;
        for(int i = 0; i < 4; i++){
            int ny = dy + pos[i][0];
            int nx = dx + pos[i][1];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] != 0) continue;
            board[ny][nx] = 2;
            visited[ny][nx] = true;
            q.push({ny,nx});
        }
    }
}

void solution(){

    //방문 여부 초기화
    visited.clear();
    visited.resize(n,vector<bool>(m, false));
    vector<vector<int>> tmp = arr;

    //바이러스 발견하면 bfs로 퍼트리기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (tmp[i][j] == 2 && !visited[i][j]){
                bfs(tmp,i,j);
            }
        }
    }

    int current = 0;

    // 바이러스 퍼트리고 나서 남은 안전 영역 구해서 res 값과 비교하기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (tmp[i][j] == 0){
                current++;
            }
        }
    }

    res = max(res, current);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    arr.resize(n,vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            //빈 칸이면 받아두었다가 아래의 3중 for문으로 돌면서 벽 세울 것 3개 고르기
            if(arr[i][j] == 0){
                plane.push_back({i,j});
            }
        }
    }

    // 벽 세울 영역 3개를 찾기
    for(int i = 0; i < plane.size(); i++){
        for(int j = i+1; j < plane.size(); j++){
            for(int k = j+1; k < plane.size(); k++){
                //조합으로 3개 찾기
                arr[plane[i].first][plane[i].second] = 1;
                arr[plane[j].first][plane[j].second] = 1;
                arr[plane[k].first][plane[k].second] = 1;
                //dfs 메서드
                solution();
                //원복
                arr[plane[i].first][plane[i].second] = 0;
                arr[plane[j].first][plane[j].second] = 0;
                arr[plane[k].first][plane[k].second] = 0;
            }
        }
    }
    cout << res;
}