#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
    int res = 0;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) res -= i;
        else res += i;
    }

        cout << "#" << t << " " << res << '\n';
    }
}