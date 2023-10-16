#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=1e3+1;
int t,n,k,dp[N][N][2]={},a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;++i) cin >> a[i];
        int ans=0;
        for(int i=1;i<=n;++i){
            int prev_mx0=dp[i-1][1][0],prev_mx1=dp[i-1][1][1],p=(a[i]%2);
            for(int j=2;j<=k;++j){
                prev_mx0=max(prev_mx0,dp[i-1][j][0]);
                prev_mx1=max(prev_mx1,dp[i-1][j][1]);
                dp[i][j][p]=max(dp[i-1][j-1][p]+a[i],dp[i-1][j][p]);
                dp[i][j][1-p]=dp[i-1][j][1-p];
            }
            if(p==1){
                dp[i][1][p]=max(dp[i-1][1][p],prev_mx0+a[i]);
                dp[i][1][1-p]=dp[i-1][1][1-p];
            }  else{
                dp[i][1][p]=max(dp[i-1][1][p],prev_mx1+a[i]);
                dp[i][1][1-p]=dp[i-1][1][1-p];
            }
        }
        for(int i=1;i<=k;++i){
            ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
        }
        cout << ans << "\n";
    }

}