#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v.push_back({x,0});
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v[i].second = x;
        }
        sort(v.begin(), v.end());
        for (auto [a,b] : v) {
            if (k >= a) {
                k+= b;
            }
            else
                break;
        }
        cout << k << '\n';
    }
}