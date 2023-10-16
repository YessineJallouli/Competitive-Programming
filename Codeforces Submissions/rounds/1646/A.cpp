#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        ll n,s; cin >> n >> s;
        cout << s/(n*n) << '\n';
    }
}