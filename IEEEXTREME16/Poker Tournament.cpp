//20%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;

ll md = 998244353;

const ll N = 1e5+7;

int dp[N][51];


inline void add(int &a,int b)
{
    a+=b;
    if (a>=md) a-=md;
}


int work(vector<int> &b, int k)
{
    int n = (int) b.size()-1;
    for (int j=1;j<=k;j++)
    {
        dp[0][j]=0;
    }
    for (int i=1;i<=n;i++)
    {
        dp[1][1]=b[i];
        for (int j=1;j<k;j++)
        {
            dp[1][j+1]=1ll*dp[0][j]*b[i]%md;
            add(dp[1][j],dp[0][j]);
        }
        add(dp[1][k],dp[0][k]);
        for (int j=1;j<=k;j++)
        {
            dp[0][j]=dp[1][j];
        }
    }
    return dp[1][k];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n,q; cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l,r,c; cin >> l >> r >> c;
            for (int i = l; i <= r; i++)
                a[i] = c;
        }
        else if (t == 1) {
            int l,r,c; cin >> l >> r >> c;
            for (int i = l; i <= r; i++)
                a[i] = max(a[i], c);
        }
        else {
            int l,r,k; cin >> l >> r >> k;
            vector<int> v;
            v.push_back(0);
            for (int i = l; i <= r; i++) {
                v.push_back(a[i]);
            }
            cout << work(v,k) << '\n';
        }
    }
}
