#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k,m=998244353;

int main() {
    ios_base::sync_with_stdio(0);
        cin >> n >> k;
        ll A[n+1],B[n+1],dp[n+1][k+1],ans=0ll;
        for(int i=0;i<=n;++i){
            for(int j=1;j<=k;++j){
                dp[i][j]=0ll;
            }
        }
        for(int i=0;i<=n;++i) dp[i][0]=1ll;
        for(int i=1;i<=n;++i) cin >> A[i] >> B[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                for(ll l=0;l<=A[i];++l){
                    if(j>=B[i]*l) dp[i][j] = (dp[i][j]+dp[i-1][j-B[i]*l])%m;
                }
            }
        }
        cout << dp[n][k] << '\n';
}
