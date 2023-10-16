//
// Created by yessine on 12/16/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        multiset<int> s;
        ll first; cin >> first;
        for (int i = 0; i < n-1; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        for (int i : s) {
            if (i < first)
                continue;
            first = (first+i+1)/2;
        }
        cout << first << '\n';
    }
}