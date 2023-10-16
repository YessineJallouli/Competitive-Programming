#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,q; cin >> n >> q;
    int a[n];
    ll sum[n+1];
    int xr[n+1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum[0] = 0;
    xr[0] = 0;
    map<int,vector<int>> oddXr;
    map<int,vector<int>> evenXr;
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i]+a[i];
        xr[i+1] = xr[i]^a[i];
        if (i%2)
            oddXr[xr[i+1]].push_back(i);
        else
            evenXr[xr[i+1]].push_back(i);
    }
    while (q--) {
        int l,r; cin >> l >> r;
        l--; r--;
        ll s = sum[r+1]-sum[l];
        int Xr = xr[r+1]^xr[l];
        if (Xr != 0)
            cout << -1 << '\n';
        else {
            if (s == 0)
                cout << 0 << '\n';
            else if ((r-l+1)%2 || a[l] == 0 || a[r] == 0)
                cout << 1 << '\n';
            else {
                int prefix = xr[l];
                if ((l+1)%2) {
                    int id = upper_bound(evenXr[prefix].begin(), evenXr[prefix].end(), l+1) - evenXr[prefix].begin();
                    int val = 2*n;
                    if (id != evenXr[prefix].size())
                        val = evenXr[prefix][id];
                    if (val <= r)
                        cout << 2 << '\n';
                    else
                        cout << -1 << '\n';
                }
                else {
                    int id = upper_bound(oddXr[prefix].begin(), oddXr[prefix].end(), l+1) - oddXr[prefix].begin();
                    int val = 2*n;
                    if (id != oddXr[prefix].size())
                        val = oddXr[prefix][id];
                    if (val <= r)
                        cout << 2 << '\n';
                    else
                        cout << -1 << '\n';
                }
            }
        }
    }
}