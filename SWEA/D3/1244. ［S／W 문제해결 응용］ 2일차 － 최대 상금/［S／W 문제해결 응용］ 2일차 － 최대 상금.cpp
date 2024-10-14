#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int ans, change;
string s;
set<pair<string, int>> visited;

void dfs(int current)
{
    if (current == change) {
        ans = max(ans, stoi(s));
        return;
    }

    if (visited.count({ s, current })) return;
    visited.insert({ s, current });

    int len = s.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            swap(s[i], s[j]);
            dfs(current + 1);
            swap(s[i], s[j]); 
        }
    }
}

int main(void)
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> s >> change;
        ans = 0;
        visited.clear();

        dfs(0);
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}
