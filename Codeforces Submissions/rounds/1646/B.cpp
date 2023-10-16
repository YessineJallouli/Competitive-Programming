#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum+= a[i];
        }
        sort(a,a+n, greater<int>());
        ll pr = 0;
        bool ans = false;
        ll pr2 = a[n-1];
        for (int i = 0; i < n; i++) {
            int nb1 = i+1;
            int nb2 = n-nb1;
            if (nb2 <= nb1)
                break;
            pr+= a[i];
            if (i != n-1)
                pr2+= a[n-i-2];
            //cout << pr << ' ' << sum-pr << '\n';
            if (pr > pr2)
                ans = true;
        }
        if (ans) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}