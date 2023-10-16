#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int mx = 0;
        int mn = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0])
                mn++;
            else if (a[i] == a[n-1]){
                mx++;
            }
        }
        if (a[0] == a[n-1]) {
            cout << 1LL * n*(n-1) << '\n';
        }
        else {
            cout << 2LL*mn*mx << '\n';
        }
    }
}