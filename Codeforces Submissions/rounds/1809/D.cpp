#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int) s.size();
        int nbZ[n+1];
        nbZ[0] = 0;
        for (int i = 0; i < n; i++) {
            nbZ[i+1] = nbZ[i];
            if (s[i] == '0')
                nbZ[i+1]++;
        }
        int nbO = 0;
        ll ans = LLONG_MAX;
        ll op1 = 1e12;
        ll op2 = 1e12+1;
        for (int i = n; i >= 0; i--) {
            int rem = n-(nbZ[i]+nbO);
            ans = min(ans, op2*rem);
            if (i != n && s[i] == '1')
                nbO++;
            if (i < n-1 && s[i] == '1' && s[i+1] == '0') {
                rem-=2;
                ans = min(ans, op2*rem+op1);
            }
            rem = n-(nbZ[i]+nbO);
            ans = min(ans, op2*rem);
        }
        cout << ans << '\n';
    }
}