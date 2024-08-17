#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i =0; i < number.size(); i++){
        int tmp = 0;
        tmp = number[i];
        for(int j = i+1; j < number.size(); j++){
            tmp += number[j];
            for(int k = j+1; k < number.size(); k++){
                tmp += number[k];
                if (tmp == 0) answer++;
                tmp -= number[k];
            }
            tmp -= number[j];
        }
    }

    return answer;
}