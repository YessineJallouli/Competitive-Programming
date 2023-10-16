#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ask(int x) {
    cout << "? " << x << endl;
    int h; cin >> h;
    return h;
}

int main() {
    int n; cin >> n;
    int s = -1;
    int l = 1, r = 5e6;
    while (l <= r) {
        int m = (l+r)/2;
        if (ask(m) == 1) {
            s = m;
            r = m-1;
        }
        else
            l = m+1;
    }
    int ans = s;
    for (int i = n; i >= 1; i--) {
        int w = s/i;
        if (w == 0)
            continue;
        int h = ask(w);
        if (h == 0 || w == 0)
            continue;
        ans = min(ans, w*h);
    }
    cout << "! " << ans << endl;
}