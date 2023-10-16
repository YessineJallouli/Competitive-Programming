#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        deque<int> d;
        d.push_back(1e9+7);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == d.back())
                continue;
            d.push_back(x);
        }
        d.push_back(1e9+7);
        int nb = 0;
        for (int i = 1; i < d.size()-1; i++) {
            if (d[i] < d[i-1] && d[i] < d[i+1])
                nb++;
        }
        if (nb == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}