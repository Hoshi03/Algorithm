#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string grades[] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++) {
        int n, num;
        cin >> n >> num;

        map<double, int> grade;
        map<int, double> score;
        vector<double> arr(n);

        for(int i = 0; i < n; i++) {
            int mid, final, subject;
            cin >> mid >> final >> subject;
            double tmp = (mid * 35 + final * 45 + subject * 20) / 300.0;
            arr[i] = tmp; //점부 벡터에 점수 저장
            score[i + 1] = tmp; // 순서 맵에 들어온 순서대로 점수 저장
        }

        sort(arr.begin(), arr.end(), greater<>());

        for(int i = 0; i < n; i++) {
            grade[arr[i]] = i + 1; // 점수 내림차순으로 등급 부여
        }

        cout << "#" << t << " " << grades[(grade[score[num]] - 1) / (n / 10)] << '\n';
    }
}
