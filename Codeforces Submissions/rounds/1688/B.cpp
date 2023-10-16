#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int p = 0, ip = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i]%2)
                ip++;
            else
                p++;
        }
        if (p == 0) {
            cout << 0 << '\n';
        }
        else if (ip == 0) {
            int mn = INT_MAX;
            for (int i = 0; i < n; i++) {
                int nb = 0;
                while (a[i]%2 == 0) {
                    a[i]/= 2;
                    nb++;
                }
                mn = min(mn, nb);
            }
            cout << p+mn-1 << '\n';
        }
        else {
            cout << p << '\n';
        }
    }
}