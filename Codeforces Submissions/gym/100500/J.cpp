#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;++i){
        int h1,h2,m1,m2;
        cin >> h1 >> m1 >> h2 >> m2;
        if((h2<h1)||(h1==h2&&m1>m2)){
            h2+=24;
        }
        cout << "Case " << i << ": " << (h2-h1)*60 + (m2-m1) << '\n';
    }

}