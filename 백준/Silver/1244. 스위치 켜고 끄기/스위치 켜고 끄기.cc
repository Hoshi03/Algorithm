#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reverse(int tmp){ //뒤집개
    if (tmp == 1) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n;
    vector<int>arr(n+1);

    for (int i = 1; i < arr.size(); i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    cin >> m;
    while (m --> 0){ // N번 돌아야 되는 반복문 돌릴때 화살표가 느낌있어서 애용합니다
        int s, cnt;
        cin >> s >> cnt;
        if (s == 1){ // 남
            for (int i = cnt; i < arr.size(); i += cnt) {
                arr[i] = reverse(arr[i]);
            }
        }

        else{ // 여
            if (cnt == 1 || cnt == arr.size()-1) arr[cnt] = reverse(arr[cnt]);//양끝
            else{
                int lt = cnt -1;
                int rt = cnt +1;
                int count = 0;
                while (lt > 0 && rt < arr.size()){
                    if (arr[lt--] != arr[rt++]) break;
                    count++;
                }
                if (count == 0) arr[cnt] = reverse(arr[cnt]);
                else{
                    for (int i = cnt- count; i <= cnt + count; ++i) {
                        arr[i] = reverse(arr[i]);
                    }
                }
            }
        }
    }

    int tmp = 0;

    for (int i = 1; i < arr.size(); i++) {
        cout << arr[i] << " ";
        tmp++;
        if (tmp % 20 == 0) {
            tmp = 0;
            cout << '\n';
        }
    }
}