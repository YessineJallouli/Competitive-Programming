#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n,k,b,s; cin >> n >> k >> b >> s;

        vector<ll> v;
        if (n == 1) {
            if (s/k != b)
                cout << -1 << '\n';
            else {
                cout << s << '\n';
            }
        }
        else {
            v.push_back(min(s, b*k+k-1));
            s-= v.back();
            for (int i = 1; i < n; i++) {
                ll mn = min(k-1, s);
                v.push_back(mn);
                s-= mn;
            }
            if (s == 0) {
                ll b1 = 0;
                for (int i = 0; i < n; i++) {
                    b1+= v[i]/k;
                }
                if (b1 == b) {
                    for (ll i : v) {
                        cout << i << ' ';
                    }
                    cout << '\n';
                }
                else {
                    cout << -1 << '\n';
                }
            }
            else {
                cout << -1 << '\n';
            }
        }

    }
}