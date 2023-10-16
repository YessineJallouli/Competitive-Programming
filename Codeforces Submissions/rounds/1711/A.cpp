#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        a[0] = 2;
        for (int i = 1; i < n; i++) {
            a[i] = i+2;
        }
        a[n-1] = 1;
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

}