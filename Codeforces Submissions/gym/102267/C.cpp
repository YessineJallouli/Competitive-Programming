#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b; cin >> a >> b;
    int ans = 0;
    while (a) {
        ans++;
        a/= b;
    }
    cout << ans;
}