#include <iostream>
#include <vector>
#include <map>

using namespace std;



bool isFull(map<int, int> mmap){
    for(int i = 0; i <= 9; i++){
        if(mmap[i] == 0) {
            return false;
        }
    }
    return true;
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        map<int, int> mmap;
        int n;
        cin >> n;

        int tmp = 0;
        int res = 0;

        while(!isFull(mmap)){
            res ++;
            tmp = res * n;
            while(tmp > 0){
                mmap[tmp % 10]++;
                tmp /= 10;
            }
        }
        cout << "#" << t << " " << res * n << '\n';
    }
}