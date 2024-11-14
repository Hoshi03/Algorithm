#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    map<string, string> mmap;
    for(int i = 0; i < n; i++){
        string s1;
        string s2;
        cin >> s1 >> s2;
        mmap[s1] = s2;
    }

    string res = "";

    for(int i = 0; i < m; i++){
        string s1;
        cin >> s1;
        res += mmap[s1] +'\n';
    }
    cout << res;
}
