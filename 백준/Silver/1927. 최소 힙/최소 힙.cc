#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string res;

    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()) res += "0\n";
            else {
                res += to_string(pq.top())+ '\n';
                pq.pop();
            }
        }
        else pq.push(tmp);
    }

    cout << res;

    return 0;
}
