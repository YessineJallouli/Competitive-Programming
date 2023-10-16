#include <bits/stdc++.h>
#define ll long long
using namespace std;

int best(int r, int k) {
    int mx = r;
    for(int j=9; j >= 0 && k != 0; j--){
        int rem = j+1;
         if (rem == k || ((r >> j) & 1) == 0) {
            r^= (1 << j);
            k--;
        }
    }
    return max(r, mx);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int pr = 0, curr = 0;
        set<int> prefixes;
        prefixes.insert(pr);
        map<int,int> last;
        for (int i = 0; i < n; i++) {
            curr^= a[i];
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pr^=a[i];
            if (last[pr] != i)
                continue;
            prefixes.insert(pr);
            for (int j : prefixes) {
                int m = j^pr;
                ans = max(ans, best(m,k));
            }
        }
        cout << ans << '\n';
    }
}