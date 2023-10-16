#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        bool one = false;
        for (int i = 0; i< n; i++) {
            cin >> a[i];
        }
        int s =0;
        for (int i = 0; i < n; i++) {
            s+= a[i];
        }
        bool ok = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] == -1 && a[i+1] == -1)
                ok = true;
            if (a[i]*a[i+1] == -1)
                one = true;
        }
        if (ok) {
            cout << s+4 << '\n';
        }
        else if (one) {
            cout << s << '\n';
        }
        else {
            cout << s-4 << '\n';
        }
    }
}