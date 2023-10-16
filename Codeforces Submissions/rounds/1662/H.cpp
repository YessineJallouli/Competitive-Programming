#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int w,l; cin >> w >> l;
        int g = __gcd(w-1,l-1);
        set<int> ans;
        for (int i = 1; i*i <= g; i++) {
            if (g%i == 0) {
                ans.insert(i);
                ans.insert(g/i);
            }
        }
        g = __gcd(w-2, l);
        for (int i = 1; i*i <= g; i++) {
            if (g%i == 0) {
                ans.insert(i);
                ans.insert(g/i);
            }
        }
        g = __gcd(w, l-2);
        for (int i = 1; i*i <= g; i++) {
            if (g%i == 0) {
                ans.insert(i);
                ans.insert(g/i);
            }
        }
        g = __gcd(w-2, l-1);
        g = __gcd(g, w);
        for (int i = 1; i*i <= g; i++) {
            if (g%i == 0) {
                ans.insert(i);
                ans.insert(g/i);
            }
        }
        g = __gcd(l-2, w-1);
        g = __gcd(g, l);
        for (int i = 1; i*i <= g; i++) {
            if (g%i == 0) {
                ans.insert(i);
                ans.insert(g/i);
            }
        }
        cout << ans.size() << ' ';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}