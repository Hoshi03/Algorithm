#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, res = 0;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[j] - '0';
			}
		}

		int mid = n / 2;
		for (int i = 0; i < n; i++) {
			int start = abs(mid - i);
			int end = n - start;
			for (int j = start; j < end; j++) {
				res += arr[i][j];
			}
		}

		cout << "#" << t << " " << res << '\n';
	}

	return 0;
}
