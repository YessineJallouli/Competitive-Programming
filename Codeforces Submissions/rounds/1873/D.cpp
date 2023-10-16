#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int k,n; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                i+= k-1;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}