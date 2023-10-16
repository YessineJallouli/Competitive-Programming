// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; int n;
        cin >> n >> s;
        vector<int> v;
        v.push_back(0);
        ll nbO = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                v.push_back(i);
            }
            if (s[i] == '1')
                nbO++;
        }
        if (s[0] == '1')
            nbO++;
        v.push_back(n);
        ll ans = 0;
        for (int i = 1; i < v.size(); i++) {
            ll block = v[i]-v[i-1];
            ans = max(ans, block*block);
        }
        ans = max(ans, nbO*(n-nbO));
        cout << ans << '\n';
    }
}