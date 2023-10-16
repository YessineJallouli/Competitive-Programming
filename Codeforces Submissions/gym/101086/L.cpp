#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=1e5+1;
int a[N]={};

int main() {
    ios_base::sync_with_stdio(0);
    int t,n;
    set<int> p={2,3,5,7,11,13,17,19};
    for(unsigned int i=1;i<N;++i){
        if(p.count(popcount(i))) a[i]++;
        a[i]+=a[i-1];
    }
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        if(l==0) cout << a[r]; else cout << a[r]-a[l-1];
        cout << '\n';
    }
}