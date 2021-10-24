#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,m,k,x,y,A[1000005],L[1000005],R[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> m >> x >> y >> k;
        priority_queue<pair<ll,ll> > pq;
        for(int i=1;i<=m*x;i++){
            cin >> A[i];
            L[i]=0;
            R[i]=0;
            pq.push({A[i],i});
        }
        ll bloc[m+1];
        for(int i=0;i<=m;++i) bloc[i]=0ll;
        ll ans=0ll,cnt=0ll;
        while(!pq.empty()&&cnt<m*y){
            ll j=pq.top().second,b=(j-1)/x;
            if((L[j-1]+R[j+1]+1<=k)&&(bloc[b]<y)){
                R[j-L[j-1]]=L[j-1]+1+R[j+1];
                L[j+R[j+1]]=R[j+1]+1+L[j-1];
                //L[j]=L[j-1]+1;
                //R[j]=R[j+1]+1;
                bloc[b]++;
                ans+=A[j];
                cnt++;
            }
            pq.pop();
        }
        if(cnt<m*y)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';

    }
}
