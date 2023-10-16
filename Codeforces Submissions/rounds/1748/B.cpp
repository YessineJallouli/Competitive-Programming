#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string ch;
            int nb[10];
            memset(nb, 0, sizeof nb);
            int df = 0;
            for (int j = i; j < min(n,i+101); j++) {
                nb[s[j]-'0']++;
                if (nb[s[j]-'0'] == 1)
                    df++;
                bool ok = true;
                for (int k = 0; k < 10; k++) {
                    if (nb[k] > df)
                        ok = false;
                }
                if (ok)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}