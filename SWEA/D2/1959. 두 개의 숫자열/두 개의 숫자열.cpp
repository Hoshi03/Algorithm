#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        int res = 0;
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n,0);
        vector<int> arr2(m,0);
        for(int i =0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr1[i] = tmp;
        }
        for(int i =0; i < m; i++) {
            int tmp;
            cin >> tmp;
            arr2[i] = tmp;
        }

        for(int k = 0; k < abs(m - n) + 1; k++) {
            int tmp = 0;
            if(arr1.size() > arr2.size()){
                for(int i = 0; i < arr2.size(); i++){
                    tmp += arr1[i + k] * arr2[i];
                }
            }

            else{
                for(int i = 0; i < arr1.size(); i++){
                    tmp += arr1[i] * arr2[i+k];
                }
            }

            res = max(res,tmp);
        }

        cout << "#" << t << " " << res << '\n';
    }
}