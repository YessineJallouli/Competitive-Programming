#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        set<int> t;
        for (int i = 0; i < n; i++) {
            t.insert(s[i]);
        }
        map<char,bool> m;
        int pr[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pr[i] = 1;
                m[s[i]] = true;
            }
            else {
                if (m.count(s[i])) {
                    pr[i] = pr[i-1];
                    continue;
                }
                m[s[i]] = true;
                pr[i] = pr[i-1]+1;
            }
        }
        map<char, bool> m1;
        int nb = 0;
        int ans = t.size();
        for (int i = n-1; i >= 1; i--) {
            if (i == n-1) {
                m1[s[i]] = true;
                nb++;
                ans = max(ans, nb + pr[i-1]);
            }
            else {
                if (m1.count(s[i])) {
                    ans = max(ans, nb + pr[i-1]);
                    continue;
                }
                m1[s[i]] = true;
                nb++;
                ans = max(ans, nb + pr[i-1]);
            }
        }
        cout << ans << '\n';
    }
}