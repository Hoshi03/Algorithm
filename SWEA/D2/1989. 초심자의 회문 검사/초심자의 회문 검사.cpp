#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        string s;
        cin >> s;

        int lt = 0, rt = s.size()-1;
        bool isPal = true;
        while(lt < rt){
            if(s[lt++] != s[rt--]){
                isPal = false;
                cout << "#" << t << " " << 0 << '\n';
                break;
            }
        }

        if(isPal) cout << "#" << t << " " << 1 << '\n';
    }
}