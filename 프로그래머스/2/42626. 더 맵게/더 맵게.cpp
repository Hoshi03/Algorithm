#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;

    while (pq.size() > 1 && pq.top() < K) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int new_scoville = a + (b * 2);
        pq.push(new_scoville);
        answer++;
    }

    if (pq.top() < K) {
        return -1;
    }
    return answer;
}