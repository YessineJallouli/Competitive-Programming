#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 1e6+7;
vector<int> dv[N];

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j+= i) {
            dv[j].push_back(i);
        }
    }

    int T; cin >> T;

    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        ll ans = 0;
        bool forb[n];
        memset(forb, false, sizeof forb);
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '1') {
                for (int j : dv[i]) {
                    forb[j-1] = true;
                }
                continue;
            }
            for (int j : dv[i]) {
                if (s[j-1] == '0' && ! forb[j-1]) {
                    ans+= j;
                    break;
                }
            }
            //s[i-1] = '1';
        }
        cout << ans << '\n';
    }
}