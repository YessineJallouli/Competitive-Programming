#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        char ans[m+1];
        for (int i = 0; i <= m; i++)
            ans[i] = 'B';
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (ans[a[i]] == 'A')
                ans[m+1-a[i]] = 'A';
            else if (ans[m+1-a[i]] == 'A')
                ans[a[i]] = 'A';
            else if (a[i] <= m+1-a[i] && ans[a[i]] == 'B') {
                ans[a[i]] = 'A';
            }
            else {
                ans[m+1-a[i]] = 'A';
            }
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i];
        cout << '\n';
    }
}