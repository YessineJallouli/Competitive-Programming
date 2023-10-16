#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        cout << min(2,n) << ' ' << min(2,m) << '\n';
    }
}