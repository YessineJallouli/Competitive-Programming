#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int ans = -1;
        int mx = 0;
        for (int i = 0; i < n; i++)  {
            cin >> a[i];
            if (mx < a[i]) {
                mx = a[i];
                ans = i+1;
            }
        }
        cout << ans << '\n';
    }
}