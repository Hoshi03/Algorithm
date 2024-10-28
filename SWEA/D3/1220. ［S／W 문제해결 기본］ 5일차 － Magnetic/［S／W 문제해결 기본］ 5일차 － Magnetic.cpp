#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {

	

	for (int t = 1; t <= 10; t++) {

		
		int res = 0;

		int n;
		cin >> n;

		vector<vector<int>> arr(n, vector<int>(n, 0));
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[j][i];
			}
		}

		// 1은 N극, 2는 S극, 1은 아래방향으로 , 2는 위 방향으로 움직임

		for (int i = 0; i < n; i++) {
			char prev = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					prev = 1;
				}
				else if (arr[i][j] == 2) {
					if (prev == 1) {
						prev = 2;
						res++;
					}
				}
			}
		}

		cout << "#" << t << " " << res << '\n';
	}
	return 0;
}