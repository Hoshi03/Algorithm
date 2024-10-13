#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr.begin(), arr.end());

		cout << "#" << t << " ";
		for (int x : arr) cout << x << " ";
		cout << '\n';

	}
	return 0;
}