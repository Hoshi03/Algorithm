#include <bits/stdc++.h>
using namespace std;



int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,res = 0;
    cin >> n;

    int arr[101] = {};
    int arrm[101] = {};

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) arr[tmp]+=1;
        else arrm[-tmp] += 1;
    }

    int find;
    cin >> find;

    if (find > 0 ) res = arr[find];
    else res = arrm[-find];
    cout << res;

}