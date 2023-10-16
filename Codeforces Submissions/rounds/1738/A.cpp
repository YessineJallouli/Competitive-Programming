#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n], b[n];
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i <n ; i++) {
            if (a[i]) {
                x.push_back(b[i]);
            }
            else {
                y.push_back(b[i]);
            }
        }
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        if (x.size() > y.size()) {
            x.swap(y);
        }
        int mn = min((int) x.size(), (int) y.size());
        ll ans = 0;
        for (int i = 0; i < mn; i++) {
            ans+= 2*x[i];
            ans+= 2*y[i];
        }
        for (int i = mn; i < y.size(); i++) {
            ans+= y[i];
        }
        if (x.size() == y.size())
            ans-= min(x.back(), y.back());
        cout << ans << '\n';
    }
}