#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll contribution(int x, int a, int y, int b, int target, vector<int> & p) {
    ll mx = 0;
    vector<int> c;
    for (int i = 1; i <= target && ! p.empty(); i++) {
        if (i%a == 0 && i%b == 0)
            c.push_back(x+y);
        else if (i%a == 0)
            c.push_back(x);
        else if (i%b == 0)
            c.push_back(y);
    }
    sort(c.rbegin(), c.rend());
    reverse(p.begin(), p.end());
    for (int i = 0; i < (int) c.size(); i++) {
        mx+= p[i]*c[i];
    }
    return mx;
}

int main() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            num[i]/= 100;
        }
        sort(num, num+n);
        int x,y,a,b; cin >> x >> a >> y >> b;
        ll k; cin >> k;
        int l = 1, r = n;
        int ans = -1;
        while (l <= r) {
            vector<int> p(n);
            for (int i = 0; i < n; i++)
                p[i] = num[i];
            int m = (l+r)/2;
            ll mx = contribution(x,a,y,b,m,p);
            if (mx >= k) {
                r = m-1;
                ans = m;
            }
            else {
                l = m+1;
            }
        }
        cout << ans << '\n';
    }
}