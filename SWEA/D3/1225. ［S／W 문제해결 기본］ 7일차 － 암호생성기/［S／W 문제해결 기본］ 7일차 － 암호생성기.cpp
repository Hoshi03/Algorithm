#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {

	for (int t = 1; t <= 10; t++) {
		int n; cin >> n;
		deque<int> dq(8);
		for (int i = 0; i < 8; i++) cin >> dq[i];

		bool isComplete = false;

		while (!isComplete)
		{
			for (int i = 1; i <= 5; i++) {
				int tmp = dq.front();
				dq.pop_front();
				if (tmp - i <= 0) {
					dq.push_back(0);
					isComplete = true;
					break;
				}

				else dq.push_back(tmp - i);
			}
		}


		cout << "#" << n << " ";
		for (int i = 0; i < 8; i++) cout << dq[i] << " ";
		cout << '\n';


	}

	return 0;
}