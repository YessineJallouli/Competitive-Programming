#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> c;
        for (int i = 0; i < n; i++) {
            ll s = 0;
            if (a[i] == 0 && b[i] == 0)
                continue;
            while (a[i] != 0) {
                if (b[i] > a[i] || b[i] == 0 || a[i]/b[i] < 3) {
                    int r = a[i];
                    a[i] = b[i];
                    b[i] = abs(b[i] - r);
                    s++;
                }
                else {
                    int k = a[i]/b[i];
                    if (k%2)
                        k--;
                    a[i]-= k*b[i];
                }
            }
            c.push_back(s%3);
        }
        sort(c.begin(), c.end());
        if (c.empty() || c[0] == c.back()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}