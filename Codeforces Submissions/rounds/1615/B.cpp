#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int mx = 2e5+7;
const int LOG = 20;
int nb[mx][LOG];

int main() {
    int T; cin >> T;
    for (int i = 0; i < LOG; i++)
        nb[0][i] = 1;
    for (int i = 1; i < mx; i++) {
        for (int bit = 0; bit < 20; bit++) {
            nb[i][bit] = nb[i-1][bit];
            if (i & (1 <<bit))
                continue;
            nb[i][bit]++;
        }
    }
    while (T--) {
        int l,r; cin >> l >> r;
        int res = INT_MAX;
        for (int bit = 0; bit < LOG; bit++) {
            res = min(res, nb[r][bit]-nb[l-1][bit]);
        }
        cout << res << '\n';
    }
}