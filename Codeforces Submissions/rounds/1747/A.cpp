#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll s = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s+= x;
        }
        cout << abs(s) << '\n';
    }
}