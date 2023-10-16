#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int> > cost(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i){
        for(int j=0;j<=min(m,n-i+1);++j) cin >> cost[i][j];
    }
    vector<ll> dp(n+2,LLONG_MAX);
    dp[1]=cost[1][0];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=min(i+m,i+n-i+1);++j){
            //if(j==n+1&&j-i==m) continue;
            dp[j]=min(dp[j],dp[i]+((j==n+1)?0:cost[j][0])-cost[i][j-i]);
        }
    }
    cout << dp[n+1];
}