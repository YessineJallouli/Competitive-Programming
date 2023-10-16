#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 101;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int nb[N];
        memset(nb, 0, sizeof nb);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nb[x]++;
        }
        int ans = 0;
        int l = 0, r = N-1;
        while (l <= r) {
            int k = (l+r)/2;
            int cnt[N];
            for (int i = 0; i < N; i++) {
                cnt[i] = nb[i];
            }
            bool ok = true;
            for (int i = k; i >= 1; i--) {
                bool b = false;
                for (int j = i; j >= 1; j--) {
                    if (cnt[j] != 0) {
                        b = true;
                        cnt[j]--;
                        break;
                    }
                }
                if (! b)
                    ok = false;
                else {
                    for (int j = 0; j <= i; j++) {
                        if (cnt[j] != 0) {
                            cnt[j]--;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                l = k+1;
                ans = k;
            }
            else {
                r = k-1;
            }
        }
        cout << ans << '\n';
    }
}