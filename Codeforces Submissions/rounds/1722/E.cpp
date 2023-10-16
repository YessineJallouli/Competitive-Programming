#include <bits/stdc++.h>
#define ll unsigned long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1005;
ll h[N][N];
ll pref[N][N];

int main() {
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        memset(h, 0, sizeof h);
        memset(pref, 0, sizeof pref);

        for (int i = 0; i < n; i++) {
            int H,W; cin >> H >> W;
            h[H][W]+= H*W;
        }

        for (int i = 1; i < N; i++) {
            pref[i][0] = 0;
            for (int j = 1; j < N; j++) {
                pref[i][j] = pref[i][j-1]+h[i][j-1];
            }
        }

        while (q--) {
            ll ans = 0;
            int hs,ws,hb,wb; cin >> hs >> ws >> hb >> wb;
            for (int i = hs+1; i < hb; i++) {
                ans+= max(0ULL,pref[i][wb]-pref[i][ws+1]);
            }
            cout << ans << '\n';
        }
    }
}