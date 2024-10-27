#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    int scoreA = 0, scoreB = 0, timeA = 0, timeB = 0;
    int lastTime = 0;

    for(int t = 0; t < tc; t++){
        int team;
        string s;
        cin >> team >> s;

        int currentTime = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));

        if(scoreA > scoreB) timeA += currentTime - lastTime;
        else if(scoreB > scoreA) timeB += currentTime - lastTime;

        if(team == 1) scoreA++;
        else if(team == 2) scoreB++;

        lastTime = currentTime;
    }


    // 경기 마지막에 누가 이기고 잇었는지를 합산
    if(scoreA > scoreB) timeA += 48*60 - lastTime;
    else if(scoreA < scoreB) timeB += 48*60 - lastTime;

    string resA = "", resB = "";
    int mA = timeA / 60, sA = timeA % 60, mB = timeB / 60, sB = timeB % 60;

    if(mA < 10) resA += "0";
    resA += to_string(mA);
    resA += ":";
    if(sA < 10) resA += "0";
    resA += to_string(sA);

    if(mB < 10) resB += "0";
    resB += to_string(mB);
    resB += ":";
    if(sB < 10) resB += "0";
    resB += to_string(sB);

    cout << resA << '\n' << resB;

    return 0;
}
