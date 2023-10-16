#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int a,b; cin >> a >> b;
        int a1 = a, b1 = b;
        int nb1 = 0;
        while (a1 != b1) {
            int r = a1|b1;
            if (r == b1) {
                nb1++;
                break;
            }
            a1++;
            nb1++;
        }
        a1 = a; b1 = b;
        int nb2 = 0;
        while (a1 != b1) {
            int r = a1|b1;
            if (r == b1) {
                nb2++;
                break;
            }
            b1++;
            nb2++;
        }
        cout << min(nb1, nb2) << '\n';
    }
}