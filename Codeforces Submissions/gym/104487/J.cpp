#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int s = 0;
        sort(a, a+n);
        reverse(a,a+n);
        for (int i = 0; i < k; i++) {
            s+= a[i];
        }
        cout << s << '\n';
    }
}