#include<bits/stdc++.h>
using namespace std;

int arr[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<bool>> visited;

void bfs(vector<vector<int>>& maps, int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        y = tmp.first;
        x = tmp.second;
        for(int i = 0; i < 4; i++){
            int ny = y + arr[i][0];
            int nx = x + arr[i][1];
            if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx] ) continue;
            q.push({ny,nx});
            visited[ny][nx] = true;
            maps[ny][nx] = maps[y][x] + 1;
        }
    }
    
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int y = maps.size();
    int x = maps[0].size();
    visited.resize(y,vector<bool>(x,false));
    
    bfs(maps,0,0);
    answer = maps[y-1][x-1];
    if(answer == 0 || answer == 1) answer = -1;
    
    return answer;
}