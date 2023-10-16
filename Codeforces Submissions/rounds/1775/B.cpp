//
// Created by yessine on 1/10/23.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
int fr[N];

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> arrays(n);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                arrays[i].push_back(x);
                fr[x]++;
            }
        }
        bool can = false;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j : arrays[i]) {
                if (fr[j] == 1)
                    ok = false;
            }
            if (ok)
                can = true;
        }
        if (can) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }



        for (int i = 0; i < n; i++) {
            for (int j : arrays[i])
                fr[j]--;
        }
    }
}