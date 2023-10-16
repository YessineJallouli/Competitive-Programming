#include "bits/stdc++.h"
using namespace std;
// Hi

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n; string s; cin >> n >> s;
        map<char,int> m;
        bool ans = true;
        m[s[0]] = true;
        for (int i = 1; i < n; i++) {
           if (s[i] == s[i-1])
              continue;
           if (m[s[i]])
              ans = false;
           m[s[i]] = true;
        }
        if (ans)
         cout << "YES" << endl;
        else
         cout << "NO" << endl;
    }
    return 0;
}