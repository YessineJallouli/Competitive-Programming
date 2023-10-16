#include <bits/stdc++.h>
#define ll lo
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (i%2) {
                if((a[i]+a[1])%2)
                    ans = false;
            }
            else {
                if((a[i]+a[0])%2)
                    ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}