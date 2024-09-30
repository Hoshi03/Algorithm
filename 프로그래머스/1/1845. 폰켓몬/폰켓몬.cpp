#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, count = nums.size()/2;
    unordered_set<int> sset;
    for(int x : nums)sset.insert(x);
    if(count >= sset.size()) answer = sset.size();
    else answer = count;
    
    return answer;
}