#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
vector<int> dv[N];

ll pcm(ll a, ll b) {
    return 1LL*a*b/(__gcd(a,b));
}

int mod = 1e9+7;

int main()
{
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j+= i) {
            dv[j].push_back(i);
        }
    }

    int n; cin >> n;
    ll ans = 0;

    for (int c = 1; c <= n; c++) {
        int r = n-c;
        int sz = (int) dv[r].size();
        int nb[sz];
        for (int i = sz-1; i >= 0; i--) {
            nb[i] = r/dv[r][i]-1;
            for (int j = i+1; j < sz; j++) {
                if (dv[r][j]%dv[r][i] == 0)
                    nb[i]-= nb[j];
            }
            ans = (ans + nb[i] * pcm(dv[r][i], c))%mod;
        }
    }
    cout << ans;
}