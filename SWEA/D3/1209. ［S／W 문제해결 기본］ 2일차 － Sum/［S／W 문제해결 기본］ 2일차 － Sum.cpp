#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    for (int t = 1; t <= 10; t++) {
        int n;
        cin >> n;
        vector<vector<int>> arr(100, vector<int>(100, 0));

        int row = 0, col = 0, rowSum = 0, colSum = 0, crossSum = 0, res = 0;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 100; i++) {
            row = 0, col = 0;
            for (int j = 0; j < 100; j++) {
                if (i == j) crossSum += arr[i][j];
                row += arr[i][j];
                col+= arr[j][i];
            }
            rowSum = max(row, rowSum);
            colSum = max(col, colSum);
        }

        res = max(rowSum, max(colSum, crossSum));

        cout << "#" << n << " " << res << '\n';
    }
    return 0;
}
