#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; 
    cin >> t;
    for(int T = 1; T <= t; T++){
        int n;
        cin >> n;
        vector<vector<int>> arr(n,vector<int>(n,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j || j == 0) arr[i][j] = 1;
                else{
                    int tmp = 0;
                    if (i-1 >= 0){
                        if (j-1 >= 0) tmp += arr[i-1][j-1];
                        tmp += arr[i-1][j];
                        arr[i][j] = tmp;
                    }
                }
            }
        }

        cout << "#" << T << '\n';

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
}