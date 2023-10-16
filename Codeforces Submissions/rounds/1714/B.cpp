#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> s;
        bool z = true;
        for (int i = n-1; i >= 0; i--) {
            if (s.count(a[i])) {
                cout << i+1 << '\n';
                z = false;
                break;
            }
            s.insert(a[i]);
        }
        if (z) {
            cout << 0 << '\n';
        }
    }
    return 0;
}