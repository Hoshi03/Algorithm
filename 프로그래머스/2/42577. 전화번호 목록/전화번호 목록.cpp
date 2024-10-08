#include<bits/stdc++.h>

using namespace std;

bool solution(vector<string> p) {
    bool answer = true;
    
    sort(p.begin(), p.end());
    int lt = 0, rt = 1;
    while(lt < rt && rt < p.size()){
        if(p[rt].find(p[lt]) == 0) {
            answer = false;
            break;
        }
        else {
            lt++; rt++;
        }
    }
    
    return answer;
}