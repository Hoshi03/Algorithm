#include <iostream>
#include <algorithm>
#include <deque>
// #include <bits/stdc++.h>
using namespace std;


int main() {

    int n, m,res = 0;
    cin >> n >> m;
    deque<int> st;
    for (int i = 0; i < n; i++) st.push_back(i+1);

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        while (st.front() != tmp){
            int idx = find(st.begin(),st.end(),tmp) - st.begin();
            if (st.size() - idx > idx ) { // tmp가 덱의 앞쪽에 있다
                st.push_back(st.front());
                st.pop_front();
            }
            else{
                st.push_front(st.back());
                st.pop_back();
            }
            res++;
        }
        st.pop_front();
    }
    cout << res;

}