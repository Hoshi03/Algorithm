#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

ll a,b,c;

ll go(ll a, ll b) {
    if (b == 1) return a % c;
    ll ret = go(a, b / 2); // 2의 5승을 2의2승 * 2의 2승 * 2로 바꾸는 연산
    ret = (ret * ret) % c; // 곱해준 걸 모듈러 연산
    // 홀수인 경우에는 a를 한번 더 곱해주는 연산
    if(b%2 != 0)ret = (ret * a) % c;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    cout << go(a,b) << '\n';
    return 0;
}
