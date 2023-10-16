#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int s = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s+= a[i];
        }
        if (s%n != 0) {
            cout << "NO\n";
        }
        else {
            int k = s/n;
            bool ans = false;
            for (int i = 0; i < n; i++) {
                if (a[i] == k)
                    ans = true;
            }
            cout << (ans ? "YES\n" : "NO\n");
        }
    }
}