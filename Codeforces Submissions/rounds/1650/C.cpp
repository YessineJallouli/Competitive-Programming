#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        vector<tuple<int,int,int>> p;
        for (int i = 0; i < m; i++) {
            int x,w; cin >> x >> w;
            p.push_back({w,x,i+1});
        }
        sort(p.begin(), p.end());
        vector<tuple<int,int,int>> v;
        ll ans = 0;
        for (int i = 0; i < 2*n; i++) {
            int w = get<0>(p[i]);
            int x = get<1>(p[i]);
            int id = get<2>(p[i]);
            v.push_back({x,w,id});
            ans+= w;
        }
        sort(v.begin(), v.end());
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << get<2>(v[i]) << ' ' << get<2>(v[2*n-i-1]) << '\n';
        }
        cout << '\n';
    }
}