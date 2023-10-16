#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {4,8,15,16,23,42};
    int n = 4;
    int ans[n];
    int g = 0;
    for (int i = 0; i < 4; i++) {
        cout << "? " << 1 << ' ' << i+2 << endl;
        cin >> ans[i];
        g = __gcd(g, ans[i]);
    }
    if (! s.count(g))
        g/= 2;
    cout << "! " << g << ' ';
    s.erase(g);
    for (int i = 0; i < n; i++) {
        cout << ans[i]/g << ' ';
        s.erase(ans[i]/g);
    }
    cout << *s.begin();
}