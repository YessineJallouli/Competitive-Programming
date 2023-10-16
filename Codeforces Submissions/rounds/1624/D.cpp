#include <bits/stdc++.h>
#define ll long long
#define Iceberg main
using namespace std;


int Iceberg() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int nb[26];
        memset(nb, 0, sizeof nb);
        string s; cin >> s;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            nb[s[i]-'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            sum+= (nb[i]-nb[i]%2);
        }
        sum/= 2;
        ans = sum/k;
        ans*= 2;
        int res = -ans*k;
        for (int i = 0; i < 26; i++)
            res+= nb[i];
        if (res >= k)
            ans++;
        cout << ans << '\n';
    }
}