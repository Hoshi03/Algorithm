#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int t = 1; t <= 10; t++) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int res = 0;
        for(int i = 2; i < n-2; i++) {
            int tmpL = 0;
            int tmpR = 0;
            bool isAble = true;
            // 왼
            for(int j = i-2; j < i; j++) {
                if(arr[j] < arr[i]) {
                    if(tmpL == 0) tmpL =arr[i] - arr[j];
                    else tmpL = min(tmpL,arr[i] - arr[j]);
                }
                else {
                    isAble = false;
                    break;
                }
            }

            // 오
            for(int j = i+1; j <= i+2; j++) {
                if(arr[j] < arr[i]) {
                    if(tmpR == 0) tmpR = arr[i] - arr[j];
                    else tmpR = min(tmpR,arr[i] - arr[j]);
                }
                else {
                    isAble = false;
                    break;
                }
            }

            if(isAble == true) res += min(tmpL, tmpR);
        }

        cout << "#" << t << " " << res << '\n';
    }
    return 0;
}