//48%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;



const int mod = 1e9 + 7;
long long fast_pow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b/= 2;
    }
    return ans;
}

struct xorBasis {
    int basis[20];
    void clear(){
        memset(basis, 0,sizeof basis);
    }
    void addVector(int x) {
        for (int i = 0; i < 20; i++) {
            if (((1 << i) & x)  == 0) continue;
            if (basis[i])
                x^= basis[i];
            else {
                basis[i] = x;
                return;
            }
        }
    }
    int size() {
        int sz = 0;
        for (int i = 0; i < 20; i++) {
            if (basis[i])
                sz++;
        }
        return sz;
    }
};


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        xorBasis x;
        for (int i = 0; i < n; i++) {
            x.clear();
            for (int j = i; j < n; j++) {
                x.addVector(a[j]);
                ans = (ans + fast_pow(2, x.size()))%mod;
                if (x.size() == 20) {
                    int rem = n-j-1;
                    ans = (ans + (rem* fast_pow(2,20))%mod)%mod;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}
