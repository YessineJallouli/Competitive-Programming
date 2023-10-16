#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("chess.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        long long k,n,ans; cin >> n >> k;
        long long p = n/(k+1);
        ans = n*(2*p+1)-(k+1)*p*(p+1);
        cout << n*n-ans << '\n';
    }
}