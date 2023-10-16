#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int r = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                r = r|a[j];
            }
        }
        ans+= r;
    }
    cout << ans;
}