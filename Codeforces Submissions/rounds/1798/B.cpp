#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int m; cin >> m;
        vector<vector<int>> lottery(m);
        map<int,int> cnt;
        for (int i = 0; i < m; i++) {
            int n; cin >> n;
            for (int j = 0; j < n; j++) {
                int x; cin >> x;
                cnt[x]++;
                lottery[i].push_back(x);
            }
        }
        map<int,int> new_cnt;
        vector<int> winners;
        for (int i = 0; i < m; i++) {
            bool winner = false;
            for (int j : lottery[i]) {
                new_cnt[j]++;
                if (cnt[j] == new_cnt[j] && ! winner) {
                    winner = true;
                    winners.push_back(j);
                }
            }
        }
        if (winners.size() == m) {
            for (int i : winners)
                cout << i << ' ';
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}