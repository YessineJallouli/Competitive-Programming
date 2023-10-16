#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("tshirts.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++){
        int m,n,c; cin >> m >> n >> c;
        int cnt[n+1];
        memset(cnt, 0, sizeof cnt);
        vector<pair<int,int>> v;
        set<int> s;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            s.insert(x);
        }
        for (int i : s) {
            v.emplace_back(cnt[i], i);
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < (int) v.size(); i++) {
            auto [nb, e] = v[i];
            sum+= (e*e)%c;
            ans = max(ans, 1LL*sum*nb);
        }
        cout << "Case " << j << ": " <<   ans << '\n';
    }
}