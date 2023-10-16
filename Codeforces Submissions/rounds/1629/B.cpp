#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int nb(int n) {
    return n/2;
}


int main() {
    int T; cin >> T;
    while (T--) {
        int l,r,k; cin >> l >> r >> k;
        int h = (r-l+1) - nb(r)+nb(l-1);
        //cout << nb(r)-nb(l-1) << '\n';
        if (k >= h) {
            cout << "YES\n";
        }
        else if (k == r-l && r != 1){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}