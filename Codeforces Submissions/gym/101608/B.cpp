#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+1;
int dp[N]={},a[N];

int main() {
    freopen("overcode.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;

    while (T--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        if (n <6) {
            cout << 0 << '\n';
            continue;
        }
        memset(dp,0, sizeof(dp));
        sort(a+1,a+n+1);
        for(int i=6;i<=n;++i){
            dp[i]=dp[i-1];
            if(a[i]-a[i-5]<=1000) dp[i]=max(dp[i],dp[i-6]+1);
        }
        cout << dp[n] << '\n';
    }
}