//40%
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

const int N = 2e5+7;
int cnt[N];

int main() {
    int n,m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a+n);
    int mx = a[n-1];

    if (m != 1) {
        for (int i = 0; i < N; i++) {
            if (i != mx) {
                int k = cnt[i];
                for (int bit = 0; bit <= 30; bit++) {
                    if (k & (1 << bit)) {
                        if (i+bit <= mx) {
                            cnt[i]-= (1 << bit);
                            cnt[i+bit]++;
                        }
                        else {
                            int diff = i+bit-mx;
                            cnt[i]-= (1 << bit);
                            cnt[mx]+= (1<<diff);
                        }
                    }
                }
            }
        }
        ll ans = 0;
        if (cnt[mx]%m == 0) {
            for (int i = mx-1; i >= 0; i--) {
                if (cnt[i] != 0) {
                    ans = fast_pow(2,i);
                    break;
                }
            }
        }
        ll k = (cnt[mx]+(m-1))/m;
        ans = (ans + (k * fast_pow(2,mx))%mod)%mod;
        cout << ans << '\n';
    }
    else {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + fast_pow(2, a[i]))%mod;
        }
        cout << ans;
    }
}
