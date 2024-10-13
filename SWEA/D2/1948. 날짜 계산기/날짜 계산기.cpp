#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int t = 1; t <= tc; t++) {
		int m1, m2, d1, d2;
		cin >> m1 >> d1 >> m2 >> d2;
		int prev = 0, next = 0;
		for (int i = 1; i < m1; i++) prev += month[i];
		for (int i = 1; i < m2; i++) next += month[i];
		prev += d1; next += d2;
		cout << "#" << t << " " << next - prev + 1 << '\n';
	}
	return 0;
}