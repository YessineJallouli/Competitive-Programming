#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=2e5+5;
int t,n,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;++i) cin >> a[i];
        bool flag=true;
        for(int i=1;i<n;++i) if(a[i]<=a[i-1]) flag=false;
        if(flag) cout << "Yes\n"; else cout << "No\n";
    }

}