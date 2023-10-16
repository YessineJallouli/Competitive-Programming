//
// Created by yessine on 3/31/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%2 == 0) {
            cout << -1 << '\n';
        }
        else {
            vector<int> v;
            while (n != 1) {
                int k = n / 2;
                if (k%2 == 1) {
                    v.push_back(2);
                    n = k;
                }
                else {
                    v.push_back(1);
                    n = k+1;
                }
            }
            cout << v.size() << '\n';
            for (int i = v.size()-1; i >= 0; i--) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }
}