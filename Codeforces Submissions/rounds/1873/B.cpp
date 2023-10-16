#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int p = 1;
        int mx = 0;
        int nbZ = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 0)
                p*= a[i];
            else
                nbZ++;
        }
        if (nbZ > 1) {
            cout << 0 << '\n';
            continue;
        }
        else if (nbZ == 1) {
            cout << p << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            mx = max(mx,p/a[i]*(a[i]+1));
        }
        cout << mx << '\n';
    }
}