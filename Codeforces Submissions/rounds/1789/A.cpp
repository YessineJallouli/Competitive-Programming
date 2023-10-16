#include <bits/stdc++.h>
#define repeat(n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ans = false;
        int g = 0;
        for (int i = 0; i < n; i++) {
            g = __gcd(g, a[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (__gcd(a[i], a[j]) <= 2)
                    ans = true;
            }
        }
        if (g > n || ! ans) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}