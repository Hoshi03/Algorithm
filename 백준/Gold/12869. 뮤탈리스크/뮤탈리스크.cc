#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n;
vector<int> arr = {0,0,0};
int visited[61][61][61] = {0,};

//공격타입
int attack[6][3] = {{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};

//계산 편의용 struct
struct A{
    int a, b, c;
};

int res = 0;


int bfs(int a, int b, int c){
    queue<A> q;
    q.push({a,b,c});
    visited[a][b][c] = 1;
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int na = max(0,tmp.a - attack[i][0]);
            int nb = max(0,tmp.b - attack[i][1]);
            int nc = max(0,tmp.c - attack[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[tmp.a][tmp.b][tmp.c]+1;
            q.push({na,nb,nc});
        }
    }
    return visited[0][0][0]-1;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    res = bfs(arr[0],arr[1],arr[2]);
    cout << res;

    return 0;
}