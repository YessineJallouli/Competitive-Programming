#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,b[101],w[101];

int main() {
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<m;++i) cin >> b[i] >> w[i];
        if(*max_element(b,b+m)+*max_element(w,w+m)>n)
            cout << "IMPOSSIBLE\n";
        else{
            string ans="";
            int mb= *max_element(b,b+m);
            for(int i=0;i<mb;++i) ans+='R';
            for(int i=0;i<n-mb;++i) ans +='W';
            cout << ans << '\n';
        }
    }
}