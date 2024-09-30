#include <bits/stdc++.h>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> mmap;
    for(string x : participant){
        mmap[x]++;
    } 
    for(string x : completion) mmap[x] -= 1;
    
    string res = "";
    for(auto i = mmap.begin(); i != mmap.end(); i++){
        if(i->second > 0) {
            res = i->first;
            break;
        } 
    }
    return res;
}