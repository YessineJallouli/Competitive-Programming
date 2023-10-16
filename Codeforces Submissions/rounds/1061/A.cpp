#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime;
    int n,s; cin >> n >> s;
    int ans = s/n;
    if (s%n != 0)
        ans++;
    cout << ans;
}