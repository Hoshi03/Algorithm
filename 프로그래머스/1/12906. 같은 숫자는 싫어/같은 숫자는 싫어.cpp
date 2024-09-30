#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    int past = -1;
    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i] != past) st.push(arr[i]);
        past = arr[i];
    }
    
    while(!st.empty()) {
    answer.push_back(st.top());
        st.pop();

    }

    return answer;
}