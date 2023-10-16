#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
int const N=3e5+1;
int n,m;
pi a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    int ans=0;
    priority_queue<ll,vector<ll>,greater<ll> > inact,act;
    for(int i=0;i<n;++i){
        bool fix=false;
        while(!act.empty()){
            ll x=act.top();
            if(x<=a[i].first){
                inact.push(x+m);
                act.pop();
            }else break;
        }
        while (!inact.empty()){
            if(inact.top()<a[i].first)
                inact.pop();
            else{
                ll x=inact.top();
                inact.pop();
                fix=true;
                act.push(a[i].first+a[i].second);
                break;
            }
        }
        if(!fix){
            act.push(a[i].first+a[i].second);
            ans++;
            //cout << "increment at i=" << i << '\n';
        }
    }
    cout << n-ans;
}