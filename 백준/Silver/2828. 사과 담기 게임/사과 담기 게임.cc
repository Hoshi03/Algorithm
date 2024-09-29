#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int screensize, bucketSize, t;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> screensize >> bucketSize >> t;

    int res = 0;
    int startPos = 1;
    int move = 0;

    for (int i = 0; i < t; i++) {
        int tc;
        cin >> tc;

        if (tc > bucketSize){
            move = tc - bucketSize;
            bucketSize += move;
            startPos += move;
            res += move;
        }

        else if(tc < startPos){
            move = startPos - tc;
            bucketSize -= move;
            startPos -= move;
            res += move;
        }
    }

    cout << res;
}
