#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        map<int,int> cnt;

        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x;
            cnt[x]++;
        }
        sort(a, a+n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) {
                if (a[i] != a[i-1]+1) {
                    ans+= cnt[a[i-1]];
                }
                else {
                    ans+= max(0, cnt[a[i-1]]-cnt[a[i]]);
                }
            }
        }
        ans+= cnt[a[n-1]];
        cout << ans << '\n';
    }
}