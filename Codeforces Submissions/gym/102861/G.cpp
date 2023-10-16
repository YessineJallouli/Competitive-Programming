//
// Created by ramizouari on 14/10/2021.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int mx = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        sum+= x;
        mx = max(mx, sum);
    }
    cout << 100+mx;
}