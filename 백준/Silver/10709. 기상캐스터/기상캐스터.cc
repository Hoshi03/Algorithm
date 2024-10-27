#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n,vector<char>(m));
    vector<vector<int>> res(n,vector<int>(m,0));

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) arr[i][j] = s[j];
    }


    for(int i = 0; i < n; i++){
        int cloud;
        bool isFind = false;
        for(int j = 0; j < m; j++ ){
            if(arr[i][j] == 'c'){
                isFind = true;
                cloud = 0;
                res[i][j] = cloud;
            }
            else {
                if(!isFind) res[i][j] = -1;
                else res[i][j] = ++cloud;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << res[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
