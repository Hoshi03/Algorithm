#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for(int T = 1; T <= t; T++){

        int s1, s2Basic, s2Limit, s2Plus, sudo;
        cin >> s1 >> s2Basic >> s2Limit >> s2Plus >> sudo;

        int s1Sum, s2Sum;

        s1Sum = s1 * sudo;

        if(sudo <= s2Limit) s2Sum = s2Basic;
        else{
            s2Sum = s2Basic + s2Plus * (sudo - s2Limit);
        }
        cout << "#" << T << " " << min(s1Sum, s2Sum) << '\n';
    }
}