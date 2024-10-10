#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                int tmp;
                cin >> tmp;
                arr[i][j] = tmp;
            }
        }

        int max = -1;
        int tmp = 0;

        for(int i =0; i <= n - m; i++){
            for(int j = 0; j <= n - m; j++){
                //여기부터 파리채로 때린 넓이 구하기
                tmp = 0;
                for(int k = i; k < i + m; k++){
                    for(int l = j; l < j+m; l++){
                        tmp += arr[k][l];
                    }
                }
                if(tmp > max) max = tmp;
            }
        }
        cout << "#" << t << " " << max << '\n';
    }
    return 0;
}