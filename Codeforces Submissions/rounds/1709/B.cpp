#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    int q; cin >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b1[n-1];
    int b2[n-1];
    for (int i = 0; i < n-1; i++) {
        b1[i] = max(0, a[i]-a[i+1]);
        b2[i] = max(0, a[i+1]-a[i]);
    }
    ll pr1[n];
    ll pr2[n];
    pr1[0] = pr2[0] = 0;
    for (int i = 1; i < n; i++) {
        pr1[i] = pr1[i-1]+b1[i-1];
        pr2[i] = pr2[i-1]+b2[i-1];
    }
    for (int i = 0; i < q; i++) {
        int l,r; cin >> l >> r;
        l--; r--;
        if (l == r) {
            cout << 0 << '\n';
        }
        else if (l < r) {
            cout << pr1[r]-pr1[l] << '\n';
        }
        else {
            cout << pr2[l]-pr2[r] << '\n';
        }
    }
}