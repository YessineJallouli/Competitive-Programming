#include <bits/stdc++.h>
#define ll long double
using namespace std;

tuple<ll,ll,ll> findCircle(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll x12 = x1 - x2;
    ll x13 = x1 - x3;

    ll y12 = y1 - y2;
    ll y13 = y1 - y3;

    ll y31 = y3 - y1;
    ll y21 = y2 - y1;

    ll x31 = x3 - x1;
    ll x21 = x2 - x1;

    if (((y31) * (x12) - (y21) * (x13) == 0) || (((x31) * (y12) - (x21) * (y13)) == 0))
        return {-1,-1,-1};
    
    ll sx13 = x1*x1 - x3*x3;

    // y1^2 - y3^2
    ll sy13 = y1*y1 - y3*y3;

    ll sx21 = x2*x2 - x1*x1;
    ll sy21 = y2*y2 - y1*y1;
    ll f = ((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) / (2 * ((y31) * (x12) - (y21) * (x13)));
    ll g = ((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) / (2 * ((x31) * (y12) - (x21) * (y13)));
    
    ll c = -1LL*x1*x1 - y1*y1 - 2LL * g * x1 - 2 * f * y1;

    ll h = -g;
    ll k = -f;
    ll sqr_of_r = h * h + k * k - c;
    return {h,k,sqr_of_r};
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        // C(n,3) = n*(n-1)*(n-2) / 6
        int n; cin >> n;
        map<tuple<ll,ll,ll>, long long> cnt;
        ll x[n], y[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        long long ans = 2;
        long long mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    auto [a,b,c] = findCircle(x[i], y[i], x[j], y[j], x[k], y[k]);
                    if (c != -1) {
                        cnt[{a,b,c}]++;
                        mx = max(mx, cnt[{a,b,c}]);
                    }
                }
            }
        }
        mx*= 6;
        long long res = 1;
        while (res*(res-1)*(res-2) != mx) {
            res++;
        }
        cout << max(res, ans) << '\n';
    }
}