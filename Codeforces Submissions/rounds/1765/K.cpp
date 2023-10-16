#include <bits/stdc++.h>
using namespace std;
int const N=201;
int n,a[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    long long ans=0;
    int mn=INT_MAX;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> a[i][j];
            ans += a[i][j];
        }
    }
    for(int i=0;i<n;++i) mn = min(mn,a[i][n-1-i]);
    ans=ans-mn;
    cout << ans;
}