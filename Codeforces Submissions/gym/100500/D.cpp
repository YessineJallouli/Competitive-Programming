#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("tshirts.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++){
        int n,d,c; cin >> n >> d >> c;
        int a[n];
        long long ans = 1LL*n*d;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        for (int i = 0; i < n; i++) {
            ans = min(ans, 1LL*a[i]*c*(i+1) + 1LL*(n-i-1)*d);
        }
        cout << "Case " << j << ": " << ans << '\n';
    }
}