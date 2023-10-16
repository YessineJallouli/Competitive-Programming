#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int mod = 998244353;
    //ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int L,R; cin >> L >> R;
        int k = L;
        set<int> s;
        while (k <= R) {
            s.insert(k);
            k*= 2;
        }
        // all two
        int l = L, r = R;
        int mx = -1;
        while (l <= r) {
            int m = (l+r)/2;
            k = m;
            set<int> s1;
            while (k <= R) {
                s1.insert(k);
                k*= 2;
            }
            if (s1.size() == s.size()) {
                mx = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        long long ans = mx-L+1;
        // one three
        l = L, r = R;
        mx = -1;
        while (l <= r) {
            int m = (l+r)/2;
            set<int> s1;
            k = m;
            while (k <= R) {
                s1.insert(k);
                if (k == m)
                    k*= 3;
                else
                    k*= 2;
            }
            if (s1.size() == s.size()) {
                mx = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        if (mx != -1) {
            long long nb = mx-L+1;
            long long HH = (int) s.size()-1;
            nb = (nb * HH)%mod;
            ans = (ans + nb)%mod;
        }
        cout << s.size() << ' ' << ans << '\n';
    }
}