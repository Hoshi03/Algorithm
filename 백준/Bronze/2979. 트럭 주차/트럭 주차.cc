#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main()
{
    int c,b,a,res = 0;
    cin >> c >> b >> a;
    int money[4] = {0, };
    money[1] = c;
    money[2] = b;
    money[3] = a;

    int time[101] = {0,};

    for (int i = 0; i < 3; i++) {
        int a,b;
        cin >> a >> b;
        for (int j = a+1; j <= b ; j++) {
            time[j]++;
        }
    }

    for (int i = 1; i <= 100 ; i++) {
        if (time[i] != 0) {
            res += money[time[i]] * time[i];
//            cout << "car count : " << time[i] << " curent res : " << res << '\n';
        }
    }

    cout << res;
}

//0 1 1 1 1 1
//    0 1 1
//  0 1 1 1 1 1 1
//
//15+12 + 6
//27