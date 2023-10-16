#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i]%2)
                a[i]+= a[i]%10;
        }
        sort(a, a+n);
        bool ans = true;
        for (int i = 0; i < n; i++) {
            int diff = (a[n-1]-a[i])%20;
            if (a[i] != a[n-1] && a[i] % 10 == 0)
                ans = false;
            if (diff == 0)
                continue;
            if (a[i]%10 == 2) {
                if (diff != 2 && diff != 6 && diff != 14)
                    ans = false;
            }
            if (a[i]%10 == 4) {
                if (diff != 4 && diff != 12 && diff != 18)
                    ans = false;
            }
            if (a[i]%10 == 8) {
                if (diff != 8 && diff != 14 && diff != 16)
                    ans = false;
            }
            if (a[i]%10 == 6) {
                if (diff != 6 && diff != 8 && diff != 12)
                    ans = false;
            }
        }
        cout << (ans ? "Yes\n" : "No\n");
//        --> 6 + 2 + 4 + 8 + 6
    }
}