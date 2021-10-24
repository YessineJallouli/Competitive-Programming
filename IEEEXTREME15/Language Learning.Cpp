#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k,m=1e9+7;


int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s[n+1];
        for(int i=1;i<=n;++i) cin >> s[i];
        ll dp[n+1],prf[n+1];
        map<string,vector<int> > mp;
        map<string, long long> mp1;
        dp[0]=0;
        prf[0]=0;
        dp[1]=1;
        prf[1]=1;
        mp[s[1]].push_back(1);
        mp1[s[1]] = 1;
        for(int i=2;i<=n;++i){
            int l=max(0,i-k-1);
            dp[i]=(prf[l]+1)%m;
            //for(int j: mp[s[i]]) dp[i] = (dp[i]-dp[j]+m)%m;
            dp[i] = (dp[i]-mp1[s[i]]+m)%m;
            prf[i]=(prf[i-1]+dp[i])%m;
            mp[s[i]].push_back(i);
            mp1[s[i]] = (mp1[s[i]] + dp[i])%m;
        }
        cout << prf[n] << '\n';
    }
}
