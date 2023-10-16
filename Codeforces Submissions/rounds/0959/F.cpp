#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct xorBasis {
    int basis[31];
    void clear(){
        memset(basis, 0,sizeof basis);
    }
    void addVector(int x) {
        for (int i = 0; i < 31; i++) {
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
        for (int i = 0; i < 31; i++) {
            if (basis[i])
                sz++;
        }
        return sz;
    }
};

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

int main() {
    xorBasis base;
    base.clear();
    int n,q; cin >> n >> q;
    int basis[n][31];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        base.addVector(x);
        for (int j = 0; j < 31; j++) {
            basis[i][j] = base.basis[j];
        }
    }
    while (q--) {
        int l,x; cin >> l >> x;
        l--;
        bool representable = true;
        int sz = 0;
        for (int i = 0; i < 31; i++) {
            if (x & (1 << i)) {
                if (! basis[l][i])
                    representable = false;
                x^= basis[l][i];
            }
            if (basis[l][i])
               sz++;
        }
        if (! representable) {
            cout << 0 << '\n';
        }
        else {
            cout << fast_pow(2, l-sz+1) << '\n';
        }
    }
}