#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int l,w,n,x=0,y=0,m;
    cin >> l >> w >> n;
    m=(l*w)/n;
    for(int i=1;i<=m;++i){
        if(m%i==0&&l%i==0&&w%(m/i)==0){
            x=i;
            y=m/i;
        }
    }
    //cout << m << ' ' << x << ' ' << y << '\n';
    if(x==0||l*w!=n*m){
        cout <<"IMPOSSIBLE";
        return 0;
    }
    vector<string> v(l,string(w,'*'));
    char c='A';
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            if(v[i][j]=='*'){
                for(int k=0;k<x;k++){
                    for(int kk=0;kk<y;kk++){
                        v[i+k][j+kk]=c;
                    }
                }
                c++;
            }
        }
    }
    for(int i=0;i<l;i++) {
        cout << v[i] << '\n';
    }
}