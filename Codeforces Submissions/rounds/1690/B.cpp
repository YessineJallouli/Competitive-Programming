#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
//        sort(a, a + n);
//        sort(b, b + n);
        bool ans = true;
        set<int> s;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                mx = max(mx, a[i]);
                continue;
            }
            if (a[i] < b[i])
                ans = false;
            s.insert(a[i]-b[i]);
        }
        if (s.size() > 1) {
            ans = false;
        }
        if (s.size() == 1) {
            if (*s.begin() < mx) {
                ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}