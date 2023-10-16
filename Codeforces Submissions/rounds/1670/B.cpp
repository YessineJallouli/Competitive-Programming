#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int prev = 0;
        int k; cin >> k;
        map<char,bool> special;
        for (int i = 0; i < k; i++) {
            char c; cin >> c;
            special[c] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (special[s[i]]) {
                ans = max(ans, i-prev);
                prev = i;
            }
        }
        cout << ans << '\n';
    }
}