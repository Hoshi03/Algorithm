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
		int s1, b1, s2, b2;
		cin >> s1 >> b1 >> s2 >> b2;

		int si = s1 + s2;
		int bun = b1 + b2;

		if ((bun) >= 60) {
			si++;
			bun -= 60;
		}

		if (si >= 13) si -= 12;

		cout << "#" << t << " " << si << " " << bun << '\n';

	}
	return 0;
}