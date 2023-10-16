#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        set<int> s;
        int n; cin >> n;
        for (int i = 0; i <n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        if ((int) s.size() == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}