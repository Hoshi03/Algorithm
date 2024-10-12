#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){

        vector<int> arr;
        for(int i = 0; i < 10; i++){
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        double res = 0;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < 9; i++) res += arr[i];

        res /= 8.0;
        res = round(res);

        cout << "#" << t << " " << static_cast<int>(res) << '\n';
    }
}