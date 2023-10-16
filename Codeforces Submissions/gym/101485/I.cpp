#include <bits/stdc++.h>
#define ll long long;
using namespace std;
int const N=1e5+1;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n=s.length(),dim= (1<<n),l=1,r=dim,t=1,b=dim;
    for(int i=0;i<n;++i){
        int d=s[i]-'0',b1=d&1,b2=d&2;
        if(b2) l=(l+r)/2 + 1; else r=(l+r)/2;
        if(b1) t=(t+b)/2 + 1; else b=(t+b)/2;
    }
    cout << n << ' ' << t-1 << ' ' << l-1;
}