#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    int res = 0;
    int i = 666;
    while(true){
        if(to_string(i).find("666") != string::npos){
            res++;
        }
        if(res == n) break;
        i++;
    }
    cout << i;
    return 0;
}
