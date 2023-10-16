#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int a[3];
        bool ans = true;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            if (a[i] == i+1) {
                ans = false;
            }
        }
        if (a[x-1] == 0) {
            ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}