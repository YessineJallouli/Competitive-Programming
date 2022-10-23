//100%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;
const int N=2e5+5;
ll t,s,c,r[N],f[N],dp[N][2]={},a[N]={};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--){
        cin >> s >> c >> r[0];
        for(int i=1;i<=s;++i) cin >> f[i] >> r[i];
        for(int i=0;i<=s;++i) dp[i][0]=dp[i][1]=1e12;
        dp[s][0]=dp[s][1]=0;
        r[s]=0;
        for(int i=s-1;i>=0;--i) {
            int cur = c;
            for (int j = i + 1; j <= s; ++j) {
                cur -= f[j];
                if (cur < 0) break;
                dp[i][1] = min(dp[i][1], 1ll * (c - cur) * r[j]+ 500*(j!=s) + dp[j][1]);
            }
        }
        //for(int i=0;i<=s;++i) cout << dp[i][1] << ' ';
        cout << dp[0][1]+r[0]*c << '\n';
    }
}
