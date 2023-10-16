#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

ll lcm(ll a, ll b) {
    return a*b/(__gcd(a,b));
}

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (a[i] != i+2)
                ans = true;
        }
        if (!ans) {
            cout << "NO\n";
            continue;
        }
        vector<ll> b;
        int l = 1;
        for (int i = 2; i <= 22; i++) {
            l = lcm(l, i);
            b.push_back(l);
        }
        for (int i = 0; i < b.size() && i < n; i++) {
            if (a[i]%b[i] == 0) {
                ans = false;
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}