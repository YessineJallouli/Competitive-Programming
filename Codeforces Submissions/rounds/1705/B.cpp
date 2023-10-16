#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        int d = n;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                d = i;
                break;
            }
        }
        for (int i = d; i <n-1; i++) {
            ans+= max(1, a[i]);
        }
        cout << ans << '\n';
    }
}