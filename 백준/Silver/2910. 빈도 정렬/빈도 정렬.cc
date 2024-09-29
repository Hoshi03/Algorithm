#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mmap, index_map;

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first == b.first){
        return index_map[a.second] < index_map[b.second];
    }
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mmap[a[i]]++;
        if(index_map[a[i]] == 0) index_map[a[i]] = i + 1;
    }

    for(auto it : mmap){
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    }

    return 0;
}
