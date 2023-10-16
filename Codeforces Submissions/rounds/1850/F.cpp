#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int cnt[n+1];
        int ans[n+1];
        memset(cnt, 0, sizeof cnt);
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x >= 1 && x <= n) {
                cnt[x]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j+= i) {
                ans[j]+= cnt[i];
            }
        }
        int k = 0;
        for (int i = 1; i <= n; i++)
            k = max(k, ans[i]);
        cout << k << '\n';
    }
}