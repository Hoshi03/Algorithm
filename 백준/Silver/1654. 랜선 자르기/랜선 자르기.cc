#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, req;
vector<long long> arr;

long long getCount(long long len);

void binary_search() {
    long long lt = 1, rt = *max_element(arr.begin(), arr.end());
    long long res = 0;
    while (lt <= rt) {
        long long m = (lt + rt) / 2;
        if (getCount(m) >= req) {
            res = m; // 최댓값을 갱신
            lt = m + 1;
        } else {
            rt = m - 1;
        }
    }
    cout << res;
}

long long getCount(long long len) {
    long long cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        cnt += arr[i] / len;
    }
    return cnt;
}

int main() {
    cin >> k >> req;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    binary_search();
    return 0;
}
