#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        arr[i] = {weight, height};
    }

    vector<int> rank(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
                rank[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << rank[i] << " ";

    return 0;
}
