//100%
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t,T;
    cin >> T;
    t=T;
    while(t--){
        int n,m,k,b;
        cin >> n >> m >> k >> b;
        vector<vector<int> > M(n+1,vector<int>(m+1) );
        vector<vector<vector<int> >  > dp(n+1,vector<vector<int> >(m+1,vector<int>(k,-1)) );
        for(int kk=0;kk<k;++kk) dp[0][1][kk]=dp[1][0][kk]=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin >> M[i][j];
                for(int kk=0;kk<k;++kk) dp[i][j][kk]=-1;
            }
        }
        for(int i=1;i<=n;++i) {
            for (int j = 1; j <= m; ++j) {
                for(int kk=0;kk<k;++kk){
                    int p=0;
                    if(M[i][j]<b) p++;
                    if(p&&!kk) continue;
                    int prev=max(dp[i-1][j][kk-p],dp[i][j-1][kk-p]);
                    if(prev!=-1) dp[i][j][kk]=prev+M[i][j];
                    if(M[i][j]>=b){
                        int prv=max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
                        if(prv!=-1) dp[i][j][kk]=max(dp[i][j][kk],prv+M[i][j]);
                    }
                    if(kk){
                        dp[i][j][kk]=max(dp[i][j][kk],dp[i][j][kk-1]);
                    }
                }
            }
        }
        int ans=dp[n][m][k-1];
        cout << "Case " << T-t << ": ";
        if(ans==-1){
            cout << "IMPOSSIBLE\n";
        }else cout << ans << '\n';
    }

}
