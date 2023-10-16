#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        pair<int,int> a[n];
        int b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        for (int i = 0; i < n; i++) {
            b[i] = a[i].second-a[i].first;
        }
        sort(b, b+n);
        int i = 0, j = n-1;
        int ans = 0;
        while (i < j) {
            if (b[i]+b[j] < 0)
                i++;
            else {
                ans++;
                i++;
                j--;
            }
        }
        cout << ans << '\n';
    }
}