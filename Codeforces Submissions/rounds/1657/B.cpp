#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,b,x,y; cin >> n >> b >> x >> y;
        int nb = 0;
        long long s = 0;
        long long a = 0;
        while (nb < n) {
            if (a+x <= b) {
                a+= x;
            }
            else {
                a-= y;
            }
            s+= a;
            nb++;
        }
        cout << s << '\n';
    }
}