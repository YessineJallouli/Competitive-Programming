#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

ll ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    ll x; cin >> x;
    return x;
}

int main() {
    ll ans = -1;
    ll res = -1;
    for (int i = 2; i <= 26; i++) {
        ll a = ask(1,i);
        ll b = ask(i,1);
        res = 2*a;
        if (a == -1) {
            ans = i-1;
            break;
        }
        if (a != b) {
            ans = a+b;
        }
    }
    if (ans == -1)
        ans = res;
    cout << "! " << ans << endl;
}