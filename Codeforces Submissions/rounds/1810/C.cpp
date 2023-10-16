//
// Created by yessine on 3/31/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,c,d; cin >> n >> c >> d;
        int a[n];
        map<int,int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        // remove doubles
        ll ans = 0;
        vector<int> v;
        for (auto [x,y] : cnt) {
            ans+= 1LL*(y-1)*c;
            v.push_back(x);
        }
        ll mn = LLONG_MAX;
        sort(v.rbegin(), v.rend());
        ll pr = 0;
        int nb = (int) v.size();
        for (int i = 0; i < v.size(); i++) {
            ll mx = v[i];
            ll rem = mx - nb;
            mn = min(mn, 1LL*i*c + 1LL*rem * d);
            nb--;
        }
        ll k = 1LL*c*n+d;
        cout << min(k, ans + mn) << '\n';
    }
}