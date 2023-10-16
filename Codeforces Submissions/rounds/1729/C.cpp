#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int) s.size();
        int mn = min(s[0], s[n-1])-'a';
        int mx = max(s[0], s[n-1])-'a';
        vector<int> pos[26];
        for (int i = 0; i < n; i++) {
            pos[s[i]-'a'].push_back(i);
        }
        vector<int> ans;
        for (int i = mn; i <= mx; i++) {
            sort(pos[i].begin(), pos[i].end());
            for (int j : pos[i])
                ans.push_back(j);
        }
        if (ans[0] != 0)
            reverse(ans.begin(), ans.end());
        cout << mx-mn << ' ' << ans.size() << '\n';
        cout << 1 << ' ';
        for (int i : ans) {
            if (i+1 == n || i == 0)
                continue;
            cout << i + 1 << ' ';
        }
        cout << n << '\n';
    }
}