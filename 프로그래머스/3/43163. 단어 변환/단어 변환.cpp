#include <bits/stdc++.h>
using namespace std;

map<string,bool> visited;

int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    queue<pair<string,int>> q;
    q.push({begin,0});
    visited[begin] = true;
    
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        
        string s = tmp.first;
        int step = tmp.second;
        bool isChanged = false;
        for(int i = 0; i < s.size(); i++){
            string swap = s;
            for(int j = 97; j < 97 + 'z' -'a' +1; j++){
                swap[i] = j;
                //타겟과 바꾼게 같으면 즉시 리턴
                if(swap == target) return step+1;
                // 한글자 바꾼게 목록에 있고 아직 방문 안한 경우
                if(swap == s || visited[swap]) continue;
                auto it = find(words.begin(), words.end(), swap);
                if(it != words.end()){
                    //각 레벨당 방문횟수 한번만 증가시키기
                    visited[swap] = true;
                    q.push({swap,step+1});
                }
            }
        }
    }
    return 0;
}