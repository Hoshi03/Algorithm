#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int tc;
	cin >> tc;

	string code[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };

	for (int t = 1; t <= tc; t++) {
		int res = 0, row, col;
		cin >> row >> col;
        bool found = false;


		for (int i = 0; i < row; i++) {
			string s;
			cin >> s;
			int finIdx = -1;
			for (int j = s.size() - 1; j >= 0; j--) {
				//처음으로 1을 만나면 숫자코드 시작
				if (s[j] == '1') {
					finIdx = j;
					break;
				}
			}
            


			// 해당 줄이 숫자코드가 있는 줄이였다면 8개 잘라서 코드 해독하고 아니면 컨티뉴
			if (finIdx != -1 && !found) {
				vector<int> arr;

				//숫자코드 8개 뽑아내기
				for (int j = 1; j <= 8; j++) {
					// 0001101 형태로 tmp가 나옴
					string tmp = s.substr(finIdx - 7 * j + 1, 7);
					for (int k = 0; k < 10; k++) {
						//위에서 정의해둔 code 별 숫자 배열과 비교해서 값을 뽑아냄
						if (tmp == code[k]) {
							arr.push_back(k);
							break;
						}
					}
				}
				//reverse(arr.begin(), arr.end());
                
				int tmpSum = 0;
				int tmpCode = 0;
				for (int j = 0; j < 8; j++) {
					if (j % 2 == 0) tmpSum += arr[j] ;
					else tmpSum += arr[j] * 3;
					tmpCode += arr[j];
				}

				if (tmpSum % 10 == 0) {
					res += tmpCode;
                    found = true;
				}
			}
		}
		cout << "#" << t << " " << res << '\n';
	}
}
