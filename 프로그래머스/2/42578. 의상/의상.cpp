#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mmap;
    for(vector x : clothes){
        mmap[x[1]]++;
    }
    
    for(auto it = mmap.begin(); it != mmap.end(); it++){
        cout << it->first << " " << it->second << '\n';
        answer = answer * (it->second + 1);
    }
    
    
    
    return answer-1;
}