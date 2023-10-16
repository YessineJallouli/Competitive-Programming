#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int sum = 0;
        map<int,int> id;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum+= a[i];
            id[sum] = i+1;
        }
        sum = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            sum+= a[i];
            if (id.count(sum) && id[sum]-1 < i) {
                ans = max(ans, id[sum] + n-i);
            }
        }
        cout << ans << '\n';
    }
}