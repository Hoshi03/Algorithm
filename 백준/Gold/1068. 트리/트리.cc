#include<bits/stdc++.h>

using namespace std;
int n, r, temp, root, res = 0;
vector<int> adj[54];

void dfs(int here) {
    //자식이 없거나, 자식이 하난데 r이면 리프 노드
    if(adj[here].size() == 0 || (adj[here].size() == 1 && adj[here][0] == r)) res++;

    //아니면 자식마다 dfs로 탐색
    else{
        for (int there: adj[here]) {
            // r 노드는 제외하고 dfs로 연결된 자식을 탐색
            if (there == r) continue;
            dfs(there);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1) root = i;
        // temp번 노드의 자식으로 i 번째로 들어온 노드가 들어감
        else adj[temp].push_back(i);
    }

    cin >> r;
    // 루트 잘라버리면 트리 박살, 0 리턴
    if (r == root) {
        cout << 0 << "\n";
        return 0;
    }

    // 그렇지 않으면 루트부터 r 노드를 빼고 dfs
    dfs(root);

    cout << res;
    return 0;
}
