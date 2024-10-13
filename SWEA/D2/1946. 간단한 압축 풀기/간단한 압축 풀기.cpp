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
		
		cout << "#" << t << '\n';
		int len = 0;

		for (int i = 0; i < n; i++) {
			char tmp; int count;

			cin >> tmp >> count;
			while (count--) {
				cout << tmp;
				len++;
				if (len == 10) {
					cout << '\n';
					len = 0;
				}
			}
		}

		cout << '\n';

	}
	return 0;
}