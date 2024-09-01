#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int startpos = s.find('*');
    // 원본 문자열에서 앞뒤 포함되어야 하는 문자열 가져오기
    string front = s.substr(0, startpos);
    string back = s.substr(startpos+1, s.size());
    //        cout << front << " " << back << '\n';


    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        if (tmp.size() < (front.size() + back.size())) {
            cout << "NE" << '\n';
            continue;
        }

        if (front.empty() || back.empty()){
            cout << "NE" << '\n';
            continue;
        }

        // front 부분 확인: tmp의 시작이 front와 일치하는지 확인
        if (tmp.substr(0, front.size()) != front) {
            cout << "NE" << '\n';
            continue;
        }

        // back 부분 확인: tmp의 끝이 back과 일치하는지 확인
        if (tmp.substr(tmp.size() - back.size()) != back) {
            cout << "NE" << '\n';
            continue;
        }

        cout << "DA" << '\n';
    }
}
