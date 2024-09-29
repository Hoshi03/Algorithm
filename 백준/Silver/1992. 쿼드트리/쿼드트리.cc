#include<bits/stdc++.h>
#include <iostream>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int n;

string dfs(int y, int x, int size){
    if (size == 1) return to_string(board[y][x]);
    char c = board[y][x];
    string ret = "";
    bool flag = false;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (c != board[i][j]){
                ret += '(';
                ret += dfs(y,x, size/2);
                ret += dfs(y,x + size/2, size/2);
                ret += dfs(y + size/2, x, size/2);
                ret += dfs(y + size/2, x + size/2, size/2);
                ret += ')';
                return ret;
            }
        }
    }
    return to_string(board[y][x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    board.resize(n,vector<int>(n,0));
    visited.resize(n,vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    cout << dfs(0,0,n);
}
