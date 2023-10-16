#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                ans+= s[i]-'0'+'a'-1;
                continue;
            }
            if (i == n-2) {
                ans+= s[i]-'0'+'a'-1;
                ans+= s[i+1]-'0'+'a'-1;
                break;
            }
            if (s[i+2] == '0') {
                if (i < n-2 && s[i+3] == '0') {
                    ans+= s[i]-'0'+'a'-1;
                    continue;
                }
                int k = (s[i]-'0')*10 + s[i+1]-'0'-1;
                ans+= k+'a';
                i+= 2;
                continue;
            }
            ans+= s[i]-'0'+'a'-1;
        }
        cout << ans << '\n';
    }
}