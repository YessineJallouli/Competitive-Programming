#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,q; cin >> n >> q;
        int a[n];
        vector<int> pr(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n, greater<int> ());
        pr[0] = a[0];
        for (int i = 1; i < n; i++)
            pr[i] = pr[i-1] + a[i];
        while (q--) {
            int x; cin >> x;
            auto id = lower_bound(pr.begin(), pr.end(), x) - pr.begin();
            if (id == n) 
                cout << -1 << '\n';
            else
                cout << id+1 << '\n';
        }
    }
}