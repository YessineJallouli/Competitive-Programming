#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int q; cin >> q;
        long long l1, l2;
        l1 = l2 = 0;
        bool a1,a2;
        a1 = true;
        a2 = true;
        while (q--) {
            int d,k; cin >> d >> k;
            string s; cin >> s;
            sort(s.begin(), s.end());
            if (d == 1) {
                l1+= 1LL * (long long) s.size() * k;
                if (s.back() != 'a') {
                    a1 = false;
                }
            }
            else if (d == 2) {
                l2+= 1LL * (long long) s.size() * k;
                if (s.back() != 'a') {
                    a2 = false;
                }
            }
            if (a1 && a2) {
                if (l1 < l2) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else if (a2 && !a1) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
}