#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<string, int> nb;
        string ch[n];
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            ch[i] = s;
            nb[s]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            char c1 = ch[i][0];
            char c2 = ch[i][1];
            for (char s1 = 'a'; s1 <= 'k'; s1++) {
                if (s1 == c1)
                    continue;
                string ss = "";
                ss+= s1;
                ss+= c2;
                ans+= nb[ss];
            }
            for (char s1 = 'a'; s1 <= 'k'; s1++) {
                if (s1 == c2)
                    continue;
                string ss = "";
                ss+= c1;
                ss+= s1;
                ans+= nb[ss];
            }
        }
        cout << ans/2 << '\n';
    }
}