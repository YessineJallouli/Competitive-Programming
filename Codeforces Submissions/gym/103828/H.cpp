#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<long long,long long>
const int N=2e5+5;
ll T,n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> n;
        if(n==4)
            ans=1;
        else if(n%2)
            ans=0;
        else{
            if(n%4==0)
                ans=n*((n-4)/4)+n/4;
            else
                ans = n*((n-2)/4);
        }
        cout << ans << '\n';
    }
}