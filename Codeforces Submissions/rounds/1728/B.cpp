#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%2) {
            cout << 1 << ' ';
        }
        for (int i = n - 2; i >= 2; i--)
            cout << i << ' ';
        if (n%2 == 0)
            cout << 1 << ' ';
        cout << n - 1 << ' ' << n << '\n';
    }
}