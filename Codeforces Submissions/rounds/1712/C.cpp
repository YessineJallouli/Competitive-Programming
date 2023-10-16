#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> s;
        for (int i = n-2; i >= 0; i--) {
            if (a[i] > a[i+1]) {
                for (int j = i; j >= 0; j--) {
                    s.insert(a[j]);
                    a[j] = 0;
                }
                for (int j = i+1; j < n; j++) {
                    if (s.count(a[j])) {
                        a[j] = 0;
                    }
                }
                break;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == 0) {
                for (int j = i-1; j >= 0; j--) {
                    if (a[j] != 0) {
                        s.insert(a[j]);
                    }
                }
                break;
            }
        }
        cout << s.size() << '\n';
    }
}