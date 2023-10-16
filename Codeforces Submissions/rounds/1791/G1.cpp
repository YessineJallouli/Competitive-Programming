#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,c; cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]+=i+1;
        }
        sort(a,a+n);
        int ans = 0;
        for (int i =0; i < n; i++) {
            if (c-a[i] >= 0) {
                ans++;
                c-= a[i];
            }
        }
        cout << ans << '\n';
    }
}