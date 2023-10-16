#include <bits/stdc++.h>
#define ll long long;
using namespace std;
int const N=1e5+1;
int a[N],n;

int dec(int y){
    int x=y%2,p=y%2,l=1;
    for(int i=1;i<8;++i){
        int b= (1<<i);
        if(y&b){
            x+=b*(1-p);
            p=1-p;
        }else x+=b*p;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) cout << dec(a[i]) << ' ';
}