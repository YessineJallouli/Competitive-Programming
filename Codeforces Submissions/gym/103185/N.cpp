#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=0;

int main(){
    cin >> n;
    string s[n+1];
    long double a[n+1],r[n+1];
    for(int i=0;i<=n;++i){
        cin >> s[i];
        s[i] = s[i].substr(1,s[i].length()-1);
        a[i]= stod(s[i]);
        if(i==0) continue;
        a[i]+=a[i-1];
        if(abs(round(a[i])-a[i]) > 1e-6) ans++;
    }
    cout << ans;
}