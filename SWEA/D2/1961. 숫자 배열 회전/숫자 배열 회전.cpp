#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        int n;
        cin >> n;
        vector<vector<int>> arr(n,vector<int> (n,0));


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int tmp;
                cin >> tmp;
                arr[i][j] = tmp;
            }
        }

        vector<string> res(n,"");

        int cnt = 0;

        for(int i = n - 1; i >= 0; i--){
            string temp = "";
            for(int j = n-1; j >= 0; j--){
                temp += to_string(arr[j][n-i-1]);
            }
            cnt %= n;
            res[cnt++] += temp += " ";
        }

        cnt = 0;

        for(int i = n - 1; i >= 0; i--){
            string temp = "";
            for(int j = n-1; j >= 0; j--){
                temp += to_string(arr[i][j]);
            }
            cnt %= n;
            res[cnt++] += temp += " ";
        }

        cnt = 0;

        for(int i = n-1; i >= 0; i--){
            string temp = "";
            for(int j = n-1; j >= 0; j--){
                temp += to_string(arr[n-j-1][i]);
            }
            cnt %= n;
            res[cnt++] += temp += " ";
        }

        cout << "#" << t << '\n';

        for(string x : res){
            cout << x << '\n';
        }
    }
}