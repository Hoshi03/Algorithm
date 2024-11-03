#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



int pos[4][2] = {{1, 0},{0, 1},{-1, 0},{0,  -1}};
int n, l, r, sum, cnt = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> country;

void dfs(int dy, int dx, vector<pair<int, int>> &v){
    for(int i = 0; i < 4; i++){
        int ny = dy + pos[i][0];
        int nx = dx + pos[i][1];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx]) continue;
        int tmp = abs(arr[ny][nx] - arr[dy][dx]);
        //국경을 열수 있는 조건
        if(l <= tmp && tmp <= r){
            visited[ny][nx] =1;
            sum += arr[ny][nx];
            v.push_back({ny, nx});
            dfs(ny, nx, v);
        }

    }
}

void solution(){
    while(true){
        bool isUnion = false;
        //visited를 각 dfs마다 초기화하면 안되고, 전체 영역에서 dfs를 쫙 돌릴때마다 초기화
        visited.clear();
        visited.resize(n,vector<bool>(n,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    // 연합국가 리스트는 dfs를 할때마다 초기화해줘야 해당 구역에서 연합된거 찾을 수 있음
                    country.clear();
                    sum = arr[i][j];
                    country.push_back({i,j});
                    visited[i][j] = true;
                    dfs(i,j,country);
                    //크기가 1이면 연결된 나라가 없음
                    if (country.size() == 1) continue;
                    for(auto x : country){
                        arr[x.first][x.second] = sum / country.size();
                        isUnion = true;
                    }
                }
            }
        }
        if(!isUnion) break;
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    arr.resize(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    solution();
    cout << cnt;
    return 0;
}