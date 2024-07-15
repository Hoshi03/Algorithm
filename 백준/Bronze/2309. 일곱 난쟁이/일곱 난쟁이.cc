#include <bits/stdc++.h>
using namespace std;



int main(void) {

    int arr[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        arr[i] = a;
        sum = sum + a;
    }

    int tmp = 0;
    int x1 = 0,x2 = 0;

    for (int i = 0; i < 9; i++) {
        tmp = sum;
        for (int j = i+1; j < 9; j++) {
            int a = arr[i];
            int b = arr[j];
            if (tmp - (a + b) == 100) {
                x1 = a;
                x2 = b;
                break;
            }
        }
    }

    sort(arr,arr+9);

    for (int i = 0; i < 9; i++) {
        if (arr[i] == x1 || arr[i] == x2) continue;
        cout << arr[i] << "\n";
    }
}