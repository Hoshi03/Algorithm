#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> arr;


int color(int y, int x){
    int cnt, tmp, res = INT32_MAX;
    char type[] = {'W','B'};


    for(int k = 0; k < 2; k++){
        tmp = k;
        cnt = 0;
        for(int i = y; i < y+8; i++){
            for(int j = x; j < x+8; j++){
                tmp %= 2;
                if(arr[i][j] != type[tmp]) cnt++;
                tmp++;
            }
            tmp++;
        }
        res = min(cnt, res);
    }
    return res;
}

int main() {
    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            arr[i][j] = s[j];
        }
    }

    int res = INT32_MAX;

    for(int i = 0; i < n - 7; i++){
        for(int j = 0; j < m - 7; j++){
            res = min(res, color(i,j));
        }
    }

    cout << res;
}