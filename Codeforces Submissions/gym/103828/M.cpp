#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<long long,long long>
const int N=2e3+5,M=998244353;
ll T,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> x >> y;
        ll l=1,r=2e9;
        while(r>l+1){
            ll m=(r+l)/2;
            if(m*(m+1)/2>=x+y){
                r=m;
            }else l=m;
            //cout << l << ':' << r << ' ';
        }
        if(l*(l+1)/2>=x+y) r=l;
        cout << r << '\n';
    }
}