#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n], b[n];
        ll ans = 0;
        for (int i = 0; i< n; i++) {
            cin >> a[i];
            ans+= a[i];
        }
        for (int i = 0; i< n; i++) {
            cin >> b[i];
            ans+= b[i];
        }
        sort(b,b+n);
        cout << ans-b[n-1] << '\n';
    }
}