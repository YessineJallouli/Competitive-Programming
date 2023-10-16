#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=2e5+5;
int t,n,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int s=0;
        for(int i=0;i<7;++i){
            int x;
            cin >> x;
            s+=x;
        }
        cout << s << '\n';
    }

}