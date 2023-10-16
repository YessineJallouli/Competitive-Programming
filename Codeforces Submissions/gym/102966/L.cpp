#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d;


int main(){
    cin >> t;
    while(t--){
        cin >> c >> d;
        a=c;
        b=d;
        set<int> s;
        for(int i=2;i<=sqrt(c);i++){
            if(a%i==0) s.insert(i);
            while(a%i==0){
                a/=i;
            }
        }
        if(a!=1) s.insert(a);
        for(int i=2;i<=sqrt(d);i++){
            if(b%i==0) s.insert(i);
            while(b%i==0){
                b/=i;
            }
        }
        if(b!=1) s.insert(b);
        cout << s.size() << '\n' ;
    }
}