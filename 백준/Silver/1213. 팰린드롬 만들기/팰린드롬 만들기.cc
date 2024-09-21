#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int s_len = s.size();
    string res = s;
    if (s_len == 1) cout << s;
    else{
        sort(s.begin(),s.end());
        int arr[26] = {};
        for(char x : s) arr[x-65]++;

        int odd = 0;

        for(int x : arr){
            if (x %2 != 0) odd++;
            // 전체 문자열 길이가 짝수인데 홀수인 경우 잇으면 팰린드롬 불가능
            if (s_len % 2 == 0 && odd >= 1){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            // 전체 문자열 길이가 홀수면 중간에 하나 박을 수는 잇음
            if (odd >= 2) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }

        int lt = 0, rt = s_len-1;

        for(int i = 0; i < 26; i++){
            if (arr[i] != 0){
                //홀수라서 중간에 하나 박고 앞뒤로 배치하기
                if (arr[i] % 2 != 0){
                    res[s_len/2] = static_cast<char>(i+65);
                    arr[i]--;
                }
                while (arr[i] != 0){
                    res[lt++] = static_cast<char>(i+65);
                    res[rt--] = static_cast<char>(i+65);
                    arr[i] -= 2;
                }
            }
        }

        cout << res;
    }
    return 0;
}
