#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool alice = false;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[0])
                alice = true;
        }
        if (alice) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
}