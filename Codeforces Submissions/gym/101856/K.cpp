#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=1e6+5;
int t,n,m,k;

int main(){
    freopen("katryoshka.in","r",stdin);
    cin >> t;
    for(int i=1;i<=t;++i){
        cin >> n >> m >> k;
        int ans=0;
        if(n>=m){
            ans=m+(n-m)/2;
        }else{
            ans=n;
        }
        ans=min(ans,k);
        cout << "Case "<<i<<": "<< ans << '\n';
    }
}