#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    vector<int> arr;
    vector<int> res(n,0);
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(int i=n-1; i >= 0; i--){
        int tmp = arr[i];
        if (st.empty()) res[i] = -1;
        else{
            while (!st.empty()){
                int cur = st.top();
                st.pop();
                // 스택에 남아잇는 오른쪽 수가 현재 수 보다 더 큰 오큰수이면
                if (tmp < cur) {
                    res[i] = cur;
                    st.push(cur);
                    break;
                }
            }
            if (st.empty()) res[i] = -1;
        }
        // 오큰수 계산을 위해 현재 수를 스택에 추가해주기
        st.push(tmp);
    }
    for(int x : res) cout << x << " ";
    return 0;
}
