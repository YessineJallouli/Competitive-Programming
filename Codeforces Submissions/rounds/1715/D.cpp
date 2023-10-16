#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<vector<pair<int,int>>> edg(n+1);
    int ans[n];
    memset(ans, 0, sizeof ans);
    int ad[n];
    bool answered[n];
    memset(answered, false, sizeof answered);
    memset(ad, -1, sizeof ad);
    for (int i = 0; i < q; i++) {
        int a,b,x; cin >> a >> b >> x;
        if (a == b) {
            ans[a-1] = x;
            answered[a-1] = true;
            continue;
        }
        if (ad[a-1] == -1) {
            ad[a-1] = x;
        }
        else {
            ad[a-1] &= x;
        }

        if (ad[b-1] == -1) {
            ad[b-1] = x;
        }
        else {
            ad[b-1] &= x;
        }
        edg[a-1].emplace_back(b-1,x);
        edg[b-1].emplace_back(a-1,x);
    }
    for (int i = 0; i < n; i++) {
        if (answered[i]) {
            ad[i] = ans[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit <= 30; bit++) {
            bool forced = false;
            for (auto [j, x] : edg[i]) {
                if (j > i) {
                    int b1 = ((1 << bit) & ans[i]) > 0;
                    int b2 = ((1 << bit) & x) > 0;

                    if (b1 == 1)
                        continue;
                    if (b2) {
                        int x3 = ad[j];
                        if (x3 == -1)
                            ans[j] |= (1 << bit);
                        else {
                            int b3 = ((1 << bit) & x3) > 0;
                            if (b3 == 0) {
                                forced = true;
                            }
                        }
                    }
                }
            }
            if (forced) {
                ans[i] |= (1 << bit);
            }
            else {
                for (auto [j, x] : edg[i]) {
                    if (j > i) {
                        int b1 = ((1 << bit) & ans[i]) > 0;
                        int b2 = ((1 << bit) & x) > 0;

                        if (b1 == 1)
                            continue;
                        if (b2) {
                            ans[j] |= (1 << bit);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ' ;
    }


}