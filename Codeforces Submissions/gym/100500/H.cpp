#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+2;
ll T,n,m,A[N][N],dp[N][N]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(int j=2;j<N;++j) dp[0][j]=-1e18;
    for(int j=2;j<N;++j) dp[j][0]=-1e18;
    for (int t = 1; t <= T; t++){
        cin >> n >> m;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j) cin >> A[i][j];
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+A[i][j];
            }
        }
        cout << "Case " << t << ": " << dp[n][m] << '\n';
    }

}