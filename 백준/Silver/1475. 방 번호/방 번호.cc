#include <bits/stdc++.h>
using namespace std;



int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {};
    int res = 0;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int tmp = s[i] - '0';
        if (arr[tmp] == 0) {
            if (tmp == 6) {
                if (arr[9] > 0) {
                    arr[9]--;
                    continue;
                }
            }
            else if (tmp == 9) {
                if (arr[6] > 0) {
                    arr[6]--;
                    continue;
                }
            }

            res++;
            for (int j = 0; j < 10; j++) arr[j] = arr[j]+1;
            arr[tmp]--;
        }
        else arr[tmp]--;
    }

    cout << res;
}