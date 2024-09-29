#include <bits/stdc++.h>
using namespace std;
char moum[] = {'a','e','i','o','u'};

bool ismoum(char c){
    for (char x : moum) {
        if (c == x) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;

    while (true){
        cin >> s;
        if (s == "end") break;
        if (s.size()== 1) {
            cout << "<" + s + "> is acceptable.\n";
            continue;
        }
        bool hasmoum = false;
        bool isempty = false;
        char current = s[0];
        char past = s[0];
        int combo = 1;

        if (ismoum(current)) hasmoum = true;

        for(int i = 1; i < s.size(); i++){
            current = s[i];
            if (current == past){ //동일한 문자가 온 경우 e랑 o만 허용
                if (current != 'e' && current != 'o') break;
            }

            if (ismoum(current) == ismoum(past)) combo++;
            else combo = 1;
            if (combo >= 3) break;
            if (!hasmoum){
                if (ismoum(current)) hasmoum = true;
            }
            past = current;
            if (i == s.size()-1) isempty = true;
        }
        if (hasmoum && isempty) cout << "<" + s + "> is acceptable.\n";
        else cout << "<" + s + "> is not acceptable.\n";
    }

    return 0;
}
