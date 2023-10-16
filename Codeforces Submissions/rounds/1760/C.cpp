#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        set<int> s;
        int b[n];
        for (int i = 0; i <n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+n);
        for (int i = 0; i < n ; i++) {
            if (a[i] != b[n-1]) {
                cout << a[i]- b[n-1] << ' ';
            }
            else {
                cout << a[i]-b[n-2] << ' ';
            }
        }
        cout << '\n';
    }
}