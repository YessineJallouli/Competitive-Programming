#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    string s;
    cin >> n >> k >> s;
    char c='L';
    for(int i=0;i<n;++i){
        if(s[i]!=c){
            k--;
            c=s[i];
        }
        if(c=='L') c='R'; else c='L';
    }
    cout << max(k,0);
}