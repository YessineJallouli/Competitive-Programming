#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        ll ans = 0;
        int n; string s;
        cin >> n >> s;
        vector<int> swp;
        for (int i = 0; i < n; i++) {
            int nbR = n-i-1;
            int nbL = n-nbR-1;
            if (s[i] == 'R') {
                ans += nbR;
                swp.push_back(max(0, nbL-nbR));
            }
            if (s[i] == 'L') {
                ans += nbL;
                swp.push_back(max(0, nbR-nbL));
            }
        }
        sort(swp.rbegin(), swp.rend());
        for (int i = 0; i < n; i++) {
            ans+= swp[i];
            cout << ans << ' ';
        }
        cout << '\n';
    }
}