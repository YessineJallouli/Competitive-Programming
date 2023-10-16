#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n = 10;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == 'X') {
                    int k = min({n-j,n-i,i+1,j+1});
                    ans+= k;
                }
            }
        }
        cout << ans << '\n';
    }
}