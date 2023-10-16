#include <bits/stdc++.h>
#define SaveTime ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        ll a[n];
        vector<tuple<long long,int,int>> v;
        map<int,int> cnt;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        for (ll i : s) {
            //cout << cnt[i]*i << ' ' << i << ' ' << cnt[i] << '\n';
            v.push_back({cnt[i]*i, i, cnt[i]});
        }
        map<pair<int,int>, bool> bad;
        for (ll i = 0; i < m; i++) {
            ll a,b; cin >> a >> b;
            bad[{a,b}] = true;
            bad[{b,a}] = true;
        }
        sort(v.rbegin(), v.rend());
        ll ans = 0;
        vector<ll> k;
        for (ll i = 0; i < v.size(); i++) {
            auto [cont1,x1,cnt1] = v[i];
            int nb = 0;
            for (ll j = i+1; j < v.size(); j++) {
                auto [cont2, x2, cnt2] = v[j];
                if (bad[{x1,x2}])
                    continue;
                else {
                    nb++;
                    ans = max(ans, 1LL*(cnt1+cnt2)*(x1+x2));
                    if (nb == 6)
                        break;
                }
            }
        }
        cout << ans << '\n';
    }
}