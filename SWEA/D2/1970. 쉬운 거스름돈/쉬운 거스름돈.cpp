#include <iostream>

using namespace std;

int main() {

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int oman = 0, man = 0, ocheon = 0, cheon = 0, obaek = 0, baek =0, oship =0, ship = 0;

		oman += n / 50000;
		n %= 50000;
		man += n / 10000;
		n %= 10000;
		ocheon += n / 5000;
		n %= 5000;
		cheon += n / 1000;
		n %= 1000;
		obaek += n / 500;
		n %= 500;
		baek += n / 100;
		n %= 100;
		oship += n / 50;
		n %= 50;
		ship += n / 10;

		cout << "#"  << t << '\n' << oman << " " << man << " " << ocheon << " " << cheon << " "
			<< obaek << " " << baek << " " << oship << " " << ship << '\n';
	}
	return 0;
}