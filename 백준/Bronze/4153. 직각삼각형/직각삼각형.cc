#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


int main() {

    vector<int> arr(3);
    while(true){
        for(int i = 0; i < 3; i++) cin >> arr[i];
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        sort(arr.begin(),arr.end());
        if(arr[0]*arr[0]+arr[1]*arr[1] == arr[2]*arr[2]) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }


    return 0;
}