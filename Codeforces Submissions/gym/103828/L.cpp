#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<long long,long long>
const int N=505;
int T,n,M[N][N];
vector<int> p;

void permute(int l, int r, int pas){
    if(r-l<2) return;
    vector<int> left,right;
    for(int i=l;i<=r;i+=2){
        if(i==r){
            left.push_back(p[r]);
        }else{
            left.push_back(p[i]);
            right.push_back(p[i+1]);
        }
    }
    int m=l+left.size();
    for(int i=l;i<m;++i){
        p[i]=left[i-l];
    }
    for(int i=m;i<=r;++i){
        p[i]=right[i-m];
    }
    permute(l,m-1,pas*2);
    permute(m,r,pas*2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> n;
        p.clear();
        for(int i=1;i<=n;++i) p.push_back(i);
        permute(0,n-1,1);
        int ans[n][n];
        memset(ans, 0, sizeof ans);
        map<int,int> conv;
        for (int i = 1; i <= n; i++) {
            conv[i] = (i-1)*n+1;
        }
        for (int i = 0; i < n; i++) {
            ans[0][i] = p[i];
        }
        for (int i = 1; i < n; i++) {
            ans[i][0] = conv[p[i]];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] = ans[i][j-1] + ans[0][j]-ans[0][j-1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}