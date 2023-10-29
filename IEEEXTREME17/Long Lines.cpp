//100%
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,h0,a,c,q;
    cin >> n >> h0 >> a >> c >> q;
    ll h=h0,ans=0;
    vector<ll> p;
    p.push_back(h0);
    for(int i=1;i<n;++i){
        ans+=p.size();
        h = (a*h+c)%q;
        while(h>=p.back()){
            p.pop_back();
            if(p.empty()) break;
        }
        p.push_back(h);
    }
    cout << ans;
}
