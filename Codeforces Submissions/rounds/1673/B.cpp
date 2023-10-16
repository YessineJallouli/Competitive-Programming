#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        bool ans = true;
        bool vis[26];
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++) {
            vis[s[i]-'a'] = true;
        }
        for (int p = 1; p <= 27; p++) {
            for (int i = 0; i < n-p+1; i++) {
                string ch = s.substr(i, p);
                int nb[26];
                memset(nb, 0, sizeof nb);
                for (int j = 0; j < ch.size(); j++) {
                    nb[ch[j]-'a']++;
                }
                int mx = 0;
                int mn = p;
                for (int j = 0; j < 26; j++) {
                    if (!vis[j])
                        continue;
                    mx = max(mx, nb[j]);
                    mn = min(mn, nb[j]);
                }
                if (mx-mn > 1)
                    ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}