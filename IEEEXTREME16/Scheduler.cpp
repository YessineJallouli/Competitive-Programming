//100%
#include<bits/stdc++.h>
#define ll long long
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


int main() {
    int n,m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    if (m != 1) {
        cout << fast_pow(2,a[n-1]);
    }
    else {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + fast_pow(2, a[i]))%mod;
        }
        cout << ans;
    }
}
