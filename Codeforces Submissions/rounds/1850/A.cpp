#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int a,b,c; cin >> a >> b >> c;
        if (a+b >= 10 || a+c >=10 || b+c >= 10) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}