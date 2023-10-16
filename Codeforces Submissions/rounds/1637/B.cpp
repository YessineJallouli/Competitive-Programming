#include <bits/stdc++.h>
#define SaveTime ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i; k <= j; k++) {
                    if (a[k] == 0)
                        ans+= 2;
                    else
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}