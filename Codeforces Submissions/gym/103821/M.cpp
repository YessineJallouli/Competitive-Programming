#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=1e5+1;
ll t,n,f[N]={},M=1e9+7,fact[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    for(int i=1;i<N;++i){
        for(int j=i*2;j<N;j+=i) f[j]++;
    }
    for(int i=2;i<N;++i) f[i]=(f[i]+f[i-1])%M;
    fact[1]=1;
    for(ll i=2;i<N;++i) fact[i]=(fact[i-1]*i)%M;
    while(t--){
        cin >> n;
        if(n==2){
            cout << 1 << '\n';
            continue;
        }
        ll ans=fact[n-2]*f[n]%M*(n*(n-1)/2)%M;
        cout << ans << '\n';
    }
}