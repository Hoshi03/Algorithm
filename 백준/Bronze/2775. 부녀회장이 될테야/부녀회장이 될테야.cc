#include <bits/stdc++.h>

using namespace std;


int main() {


    int arr[15][15] ={0,} ;
    arr[1][1] = 1;
    for(int i = 2; i <= 14; i++) arr[1][i] = arr[1][i-1] + i;

    for(int i = 2; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            for(int k = 1; k <= j; k++){
                arr[i][j] += arr[i-1][k];
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc --> 0){
        int a,b;
        cin >> a >> b;
        cout << arr[a][b] << '\n';
    }
}