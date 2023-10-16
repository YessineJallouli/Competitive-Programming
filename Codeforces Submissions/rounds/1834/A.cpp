//
// Created by yessine on 6/24/23.
//

#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int sum = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            sum+= x;
            if (x < 0)
                neg++;
        }
        int operations = 0;
        while (sum < 0 || neg%2 == 1) {
            sum+= 2;
            neg--;
            operations++;
        }
        cout << operations << '\n';
    }
}