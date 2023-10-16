//
// Created by yessine on 6/24/23.
//

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve(string &s, string &t, bool r) {
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != t[i])
            ans++;
    }
    if (! r) {
        if (ans%2 == 1) {
            return 2*ans-1;
        }
        else
            return 2*ans;
    }
    else {
        if (ans%2 == 1)
            return 2*ans;
        else
            return max(2, 2*ans-1);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s,t; cin >> s >> t;
        string k = t;
        reverse(k.begin(), k.end());
        cout << min(solve(s,t,false), solve(s,k,true)) << '\n';
    }
}