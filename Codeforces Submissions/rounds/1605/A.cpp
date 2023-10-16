#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int a,b,c; cin >> a >> b >> c;
        int k = 2*b;
        int h = a+c;
        int diff = abs(h-k);
        cout << min(diff%3, 3-diff%3) << '\n';
    }
}