#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {

	for (int t = 1; t <= 10; t++) {
		int res = 0, n; cin >> n;
		vector<vector<char>> arr(8, vector<char>(8));

		for (int i = 0; i < 8; i++) {
			string s; cin >> s;
			for (int j = 0; j < 8; j++) arr[i][j] = s[j];
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				// 가로 문자열 가져오기
				if (8 - j >= n) {
					string tmp = "";
					for (int k = 0; k < n; k++) tmp += arr[i][j + k];
					string tmp2 = tmp;
					reverse(tmp.begin(), tmp.end());
					if (tmp == tmp2) res++;
				}

				// 세로 문자열 가져오기
				if (8 - j >= n) {
					string tmp = "";
					for (int k = 0; k < n; k++) tmp += arr[j + k][i];
					string tmp2 = tmp;
					reverse(tmp.begin(), tmp.end());
					if (tmp == tmp2) res++;
				}
			}
		}
		cout << "#" << t << " " << res  << '\n';
	}
    return 0;
}