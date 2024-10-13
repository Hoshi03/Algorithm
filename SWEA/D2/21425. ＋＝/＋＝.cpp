#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	string res = "";

	for (int t = 1; t <= tc; t++) {
		int a, b, n;
		cin >> a >> b >> n;
		int cnt = 1;
		while ((a + b) <= n) {
			int tmp = max(a, b);
			a = a + b;
			b = tmp;
			cnt++;
		}
		res += to_string(cnt);
		res += '\n';
	}

	cout << res;
	return 0;
}