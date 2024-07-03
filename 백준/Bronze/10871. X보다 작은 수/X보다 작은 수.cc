#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < m) arr.push_back(tmp);
    }

    for(int x : arr) printf("%d ", x);
}

