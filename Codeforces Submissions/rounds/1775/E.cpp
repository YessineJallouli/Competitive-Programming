//
// Created by yessine on 1/10/23.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long maxSubArraySum(vector<ll> a)
{
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
    int size = (int) a.size();
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll ans = 0;
        vector<ll> a(n);
        ll mx = 0;
        ll s = 0;
        ll prMx = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x;
            mx = max(mx, abs(a[i]));
            s+= a[i];
            prMx = max(prMx, abs(s));
        }
        ll mx1 = maxSubArraySum(a);
        for (int i = 0; i < n; i++) {
            a[i]*= -1;
        }
        ll mx2 = maxSubArraySum(a);
        s = 0;
        for (int i = n-1; i >= 0; i--) {
            s+= a[i];
            prMx = max(prMx, abs(s));
        }
        cout << max(mx1, mx2) << '\n';

    }
}