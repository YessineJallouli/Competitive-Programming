#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,c; cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        if (c >= 0) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        reverse(a, a+n);
        ll ans = 0;
        for (int i = 0; i < n-1; i++) {
            ans+= abs(a[i+1]-a[i]-c);
        }

        for (int i = 1; i < n; i++) {
            int idx = -1;
            for (int m = i; m < n-1; m++) {
                // can I take a[m] ?
                // find idx the min
                ll k = ans;
                k+= abs(a[i]-a[m]-c);
                k+= abs(a[m]-a[i-1]-c);
                k-= abs(a[m+1]-a[m]-c);
                k-= abs(a[m]-a[m-1]-c);
                k+= abs(a[m+1]-a[m-1]-c);
                k-= abs(a[i]-a[i-1]-c);
                if (k == ans)
                    idx = m;
            }
            if (idx != -1) {
                int b[n];
                for (int j = 0; j < i; j++)
                    b[j] = a[j];
                b[i] = a[idx];
                vector<int> v;
                for (int j = i; j < n; j++) {
                    if (j != idx)
                        v.push_back(a[j]);
                }
                sort(v.rbegin(), v.rend());
                for (int j = i + 1; j < n; j++)
                    b[j] = v[j - i - 1];
                ll r = 0;
                for (int j = 0; j < n - 1; j++) {
                    r += abs(b[j + 1] - b[j] - c);
                }
                if (r == ans) {
                    for (int j = i; j < n; j++) {
                        a[j] = b[j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}