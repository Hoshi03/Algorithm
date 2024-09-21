#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt;
    cin >> cnt;
    while (cnt -- > 0){
        int n;
        cin >> n;

        map<string, int> mmap;

        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;

            //해당 타입이 있으면 갯수 증가
            if (mmap.find(type) != mmap.end()){
                mmap[type]++;
            }
                //해당 타입이 없으면 맵에 삽입하기
            else mmap[type] = 1;
        }

        int res = 1;

        for (auto i = mmap.begin(); i != mmap.end(); i++) {
            res *= (i->second + 1);
        }
        //알몸인 경우 빼기
        res--;
        cout << res << '\n';
    }
    return 0;
}
