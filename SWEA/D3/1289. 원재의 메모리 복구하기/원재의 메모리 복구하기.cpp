#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {

	int tc;cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string origin; 
		cin >> origin;
		int res = 0;
		char flag = '0';

		for (char x : origin) {
			if (x != flag) {
				flag = x;
				res++;
			}
		}

		cout << "#" << t << " " << res << '\n';
	}
	return 0;
}