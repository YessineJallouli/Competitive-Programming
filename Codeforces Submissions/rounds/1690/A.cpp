#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        if (x%3 < 2)
            cout << x / 3 << ' ' << x / 3 + 1 + x%3 << ' ' << x / 3-1  << "\n";
        if (x%3 == 2) {
            cout << x/3+1 << ' ' << x/3+2 << ' ' << x/3-1 << '\n';
        }
    }
}