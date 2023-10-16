//
// Created by yessine on 4/2/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mod = 1e9+7;
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        int sz = a.size();
        vector<ll> b;
        int sq = ceil(sqrt(sz));
        for (int j = 0; j < sq; j++) {
            if (j < 10) {
                for (int k = j + 1; k < sz; k++) {
                    b.push_back(a[j] + a[k]);
                }
            }
            else {
                for (int k = j + 1; k < min(sz, j+1+sq); k++) {
                    b.push_back(a[j] + a[k]);
                }
            }
        }
        sort(b.begin(), b.end());
        a.clear();
        for (int j = 0; j < sz-1; j++) {
            a.push_back(b[j]);
        }
        if (a[0] > mod) {
            int k = a[0]/mod;
            for (int i = 0; i < a.size(); i++) {
                a[i]-= k*mod;
            }
        }
    }
    cout << a[0]%mod;
}