#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=2e5+5;
ll t,n,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        cout << n*(n-1)/2 << '\n';
    }
}