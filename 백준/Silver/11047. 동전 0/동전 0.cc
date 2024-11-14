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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int res = 0;
    int idx = n-1;
    while(m != 0){
        for(int i = idx; i >= 0; i--){
            if(arr[i] <= m){
                m -= arr[i];
                idx = i;
                res++;
                break;
            }
        }
    }

    cout << res;
}