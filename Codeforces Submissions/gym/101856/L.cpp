#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=1e6+5;
int t,n,m,q,a,b,c,d;

int main(){
    freopen("lazy.in","r",stdin);
    cin >> t;
    for(int i=1;i<=t;++i){
        cin >> n;
        int ans=0;
        while (n>1){
            m=n/2;
            ans += m;
            if(n%2) m++;
            n=m;
        }
        cout << "Case "<<i<<": "<< ans << '\n';
    }
}