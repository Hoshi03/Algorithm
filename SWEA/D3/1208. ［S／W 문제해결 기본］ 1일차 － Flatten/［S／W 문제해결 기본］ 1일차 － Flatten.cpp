#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    for (int t = 1; t <= 10; t++) {
        int dump_count;
        cin >> dump_count;
        vector<int> arr(100);
        for (int i = 0; i < 100; i++) cin >> arr[i];
        while (dump_count--) {
            int max_idx = max_element(arr.begin(), arr.end()) - arr.begin();
            int min_idx = min_element(arr.begin(), arr.end()) - arr.begin();
            if (arr[max_idx] - arr[min_idx] <= 1) break;
            arr[max_idx]--;
            arr[min_idx]++;
        }
        int a = arr[max_element(arr.begin(), arr.end()) - arr.begin()];
        int b = arr[min_element(arr.begin(), arr.end()) - arr.begin()];
        cout << "#" << t << " " << a - b << endl;
    }
    return 0;
}
