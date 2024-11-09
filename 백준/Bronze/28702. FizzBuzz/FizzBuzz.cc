#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<string> s(3);
    int tmp = 0;
    for(int i = 0; i < 3; i++) cin >> s[i];
    for(int i = 0; i < 3; i++) {
        if((s[i][0] - '0') < 10){
            tmp = stoi(s[i]) + 3 - i ;
            break;
        }
    }

    if (tmp % 3 == 0){
        if(tmp % 5 == 0){
            cout << "FizzBuzz";
        }
        else{
            cout << "Fizz";
        }
    }
    else if(tmp % 5 == 0)cout << "Buzz";
    else cout << tmp;
}