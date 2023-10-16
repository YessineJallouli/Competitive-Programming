#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int pr[n+1];
        pr[0] = 0;
        string s; cin >> s;
        for (int i = 1; i <= n; i++) {
            pr[i] = pr[i-1];
            if (s[i-1] == 'B') {
                pr[i]++;
            }
        }
        int mx = 0;
        for (int i = 0; i <= n-k; i++) {
            int sm = pr[i+k] - pr[i];
            mx = max(mx, sm);
        }
        cout << k-mx << '\n';
    }
}