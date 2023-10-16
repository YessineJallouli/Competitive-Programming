#include <bits/stdc++.h>
using namespace std;
int n,m,s=0,t=0,x;

int main(){
    cin >> n >> m;
    for(int i=0;n>i;i++){
        cin >> x;
        s+=x;
    }
    for(int i=0;m>i;i++){
        cin >> x;
        t+=x;
    }
    cout << t-s << '\n';
}