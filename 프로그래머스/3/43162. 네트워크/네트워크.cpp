#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(vector<vector<int>> computers, int current){
    visited[current] = true;
    for(int i = 0; i < computers.size(); i++){
        if(visited[i] || computers[current][i] == 0) continue;
        dfs(computers, i);
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(n,false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] == 0 || visited[i]) continue;
            else{
                answer++;
                dfs(computers, i);
            }
        }
    }
    
    return answer;
}