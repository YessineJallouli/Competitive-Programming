#include <bits/stdc++.h>
using namespace std;

vector<int> v;

const int N = 4e4+1;
long long dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    for (int i = 1; i <= 40000; i++) {
        string s = to_string(i);
        string ch = s;
        reverse(ch.begin(), ch.end());
        if (ch == s) {
            v.push_back(i);
        }
    }
    dp[0] = 1;
    int mod = 1e9+7;
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = v[i]; j < N; j++) {
            dp[j] = (dp[j] + dp[j-v[i]])%mod;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}