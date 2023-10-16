#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        if (n == 1) {
            cout << "Bob ";
            cout << s[0]-'a'+1 << '\n';
        }
        else {
            cout << "Alice ";
            int ans = 0;
            for (int i = 1; i < n-1; i++) {
                ans+= s[i]-'a'+1;
            }
            if (s[0] > s[n-1]) {
                ans+= s[0]-'a'+1;
                if (n%2 == 0)
                    ans+= s[n-1]-'a'+1;
                else
                    ans-= s[n-1]-'a'+1;
            }
            else {
                ans+= s[n-1]-'a'+1;
                if (n%2 == 0)
                    ans+= s[0]-'a'+1;
                else {
                    ans-= s[0]-'a'+1;
                }
            }
            cout << ans << '\n';
        }
    }
}