#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,l,r; cin >> n >> l >> r;
        vector<int> ans;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int k = r-r%i;
            if (k < l) {
                ok = false;
            }
            else {
                ans.push_back(k);
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int i : ans)
                cout << i << ' ';
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
}