#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken_list;

int n, m, tmp_chicken_distance = 0, res = INT16_MAX;

void solution(int pos){
    if(chicken_list.size() == m){
        // 치킨집중 m개를 고른 경우 각 집에서 치킨거리 구해주기
        tmp_chicken_distance = 0;
        for(int i = 0; i < home.size(); i++){
            int tmp = INT16_MAX;
            for(int j = 0; j < chicken_list.size(); j++){
                int currenHouse = (abs(chicken_list[j].first - home[i].first) +
                        abs(chicken_list[j].second - home[i].second));
                tmp = min(tmp, currenHouse);
            }
            tmp_chicken_distance += tmp;
        }
        res = min(res, tmp_chicken_distance);
        return;
    }
    //백트래킹
    for(int i = pos+1; i < chicken.size(); i++){
        chicken_list.push_back(chicken[i]);
        solution(i);
        chicken_list.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    arr.resize(n,vector<int>(n,0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            //치킨집 목록을 만들기 위해 따로 모아둠
            if (tmp == 2) chicken.push_back({i,j});
            // 집 목록을 구하기
            if (tmp == 1) home.push_back({i,j});
            arr[i][j] = tmp;
        }
    }

    solution(-1);
    cout << res;

    return 0;
}
