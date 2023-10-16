#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        long long mx = LLONG_MAX;
        long long mn = 0;
        while (n--) {
            int x; char c;
            cin >> x >> c;
            if (c == '+')
                mn+= x+25;
            else
                mx = min(mx, mn+x+24);
        }
        cout << mx-mn+1 << '\n';
    }
}