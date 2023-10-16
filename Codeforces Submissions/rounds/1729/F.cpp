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
        int w,m; cin >> w >> m;
        vector<int> mod9[10];
        int sm = 0;
        for (int i = 0; i < w; i++) {
            sm+= s[i]-'0';
            sm%= 9;
        }
        mod9[sm].push_back(0);
        for (int i = w; i < n; i++) {
            sm+= s[i]-'0'+9;
            sm-= s[i-w]-'0';
            sm%= 9;
            mod9[sm].push_back(i-w+1);
        }
        int pr[n+1];
        pr[0] = 0;
        for (int i = 1; i <= n; i++) {
            pr[i] = pr[i-1]+s[i-1]-'0';
        }
        while (m--) {
            int l,r,k; cin >> l >> r >> k;
            pair<int,int> ans = {n,n};
            r--; l--;
            int vlr = (pr[r+1]-pr[l])%9;
            for (int i = 0; i <= 9; i++) {
                if (mod9[i].empty())
                    continue;
                for (int j = 0; j <= 9; j++) {
                    if (mod9[j].empty())
                        continue;
                    if (((i*vlr+j)%9) == k) {
                        if (i == j) {
                            if (mod9[i].size() < 2)
                                continue;
                            ans = min(ans, {mod9[i][0], mod9[i][1]});
                        }
                        else {
                            ans = min(ans, {mod9[i][0], mod9[j][0]});
                        }
                    }
                }
            }
            if (ans.first == n) {
                cout << -1 << ' ' << -1 << '\n';
            }
            else {
                cout << ans.first+1 << ' ' << ans.second+1 << '\n';
            }
        }
    }
}