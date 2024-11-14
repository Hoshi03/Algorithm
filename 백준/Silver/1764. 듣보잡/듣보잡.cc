#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> mmap;
	map<string, int> mmap2;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mmap[s]++;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (mmap[s]> 0) mmap2[s]++;
	}


	cout << mmap2.size() << '\n';
	for (auto x : mmap2) {
		cout << x.first << '\n';
	}
}