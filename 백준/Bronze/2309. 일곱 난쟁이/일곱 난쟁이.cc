#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {

    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        sum += tmp;
    }

    bool find = false;

    for (int i = 0; i < arr.size(); i++) {
        if (find) break;
        for (int j = 1; j < arr.size(); j++) {
            if (find) break;
            if (sum - (arr[i]+arr[j]) == 100){
                arr[i] = 0;
                arr[j] = 0;
                find = true;
            }
        }
    }

    sort(arr.begin(), arr.end());

    for (int i = 2; i < 9; ++i) {
        cout << arr[i] << '\n';
    }
}