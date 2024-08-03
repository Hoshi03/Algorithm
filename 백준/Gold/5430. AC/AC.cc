#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    while (n -- > 0){
        string func,s;
        int size;
        cin >> func >> size >> s;
        bool flip = false, error = false;

        deque<int> arr;
        s.replace(s.find("["),1,"");
        s.replace(s.find("]"),1,"");
        stringstream ss1(s);
        string tmp;

        if (size != 0){
            while (getline(ss1,tmp,','))arr.push_back(stoi(tmp));
        }

        for (int i = 0; i < func.size(); i++) {
            if (func[i] == 'R'){
                if (flip == false) flip = true;
                else if(flip == true) flip = false;
            }
            else if (func[i] == 'D'){
                if(arr.empty()){
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (!flip) arr.pop_front();
                else arr.pop_back();
            }
        }




        if (error == false){
            if (arr.empty()){
                cout << "[]" << '\n';
                continue;
            }
            if (flip == false){ // 뒤집히지 않은 상태
                cout << "[";
                while (arr.size() != 1){
                    cout << arr.front() << ",";
                    arr.pop_front();
                }
                cout << arr.front();
                cout << "]" << '\n';
            }

            else{ // 뒤집힌 상태
                cout << "[";
                while (arr.size() != 1){
                    cout << arr.back() << ",";
                    arr.pop_back();
                }
                cout << arr.back();
                cout << "]" << '\n';
            }
        }
    }

}