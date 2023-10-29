//100%
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
ll MOD = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    vector<int> sum(n+1,0);

    dp[0][1]=1;
    sum[0]=1;
    for(int i=1;i<n;++i){
        if(s[i-1]=='>'){
            for(int j=2;j<=i+1;++j){
                dp[i][j] = dp[i-1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] = (dp[i][j-1]+dp[i][j])%MOD;
            }
            sum[i] = dp[i][i+1];
        }else{
            for(int j=1;j<=i;++j){
                dp[i][j] = (sum[i-1]-dp[i-1][j-1]+MOD)%MOD;
                dp[i][j] %= MOD;
                dp[i][j] = (dp[i][j-1]+dp[i][j])%MOD;
            }
            dp[i][i+1]=dp[i][i];
            sum[i] = dp[i][i];
        }
    }
    cout << dp[n-1][n];
}
