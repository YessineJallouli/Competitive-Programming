#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        vector<int> per;
        int ans = false;
        for (int i = 0; i < 2; i++) {
            vector<int> v;
            for (int j = 0; j < n/2; j++) {
                v.push_back(a[j]);
                v.push_back(a[n/2+n%2+j]);
            }
            if (n%2) {
                v.push_back(a[n/2]);
            }
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (v[j] > v[(j+1)%n] && v[j] > v[(j-1+n)%n]) {
                    continue;
                }
                if (v[j] < v[(j+1)%n] && v[j] < v[(j-1+n)%n]) {
                    continue;
                }
                ok = false;
            }
            ans = ans | ok;
            if (ok) {
                v.swap(per);
            }
            reverse(a, a+n);
        }
        if (ans) {
            cout << "YES\n";
            for (int i : per) {
                cout << i << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
}