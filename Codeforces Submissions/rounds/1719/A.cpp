#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        if ((n+m)%2 == 0) {
            cout << "Tonya\n";
        }
        else {
            cout << "Burenka\n";
        }
    }
}