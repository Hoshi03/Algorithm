#include <iostream>

using namespace std;

int main() {

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int count2 = 0, count3 = 0, count5 = 0, count7 = 0, count11 = 0;

		while (n % 2 == 0) {
			n /= 2;
			count2++;
		}

		while (n % 3 == 0) {
			n /= 3;
			count3++;
		}

		while (n % 5 == 0) {
			n /= 5;
			count5++;
		}

		while (n % 7 == 0) {
			n /= 7;
			count7++;
		}

		while (n % 11 == 0) {
			n /= 11;
			count11++;
		}

		cout << "#" << t << " " << count2 << " " << count3 << " " << count5 << " " << count7 << " "
			<<  count11 << '\n';
	}
	return 0;
}