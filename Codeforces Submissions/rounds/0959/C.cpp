#include <bits/stdc++.h>
using namespace std;

void correct(int n) {
    for (int i = 2; i <= n; i++) {
        cout << 1 << ' ' << i << '\n';
    }
}

void incorrect(int n) {
    if (n < 6) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= 4; i++) {
            cout << 1 << ' ' << i << '\n';
        }
        for (int i = 5; i <= n; i++) {
            cout << 2 << ' ' << i << '\n';
        }
    }
}

int main() {
    int n; cin >> n;
    incorrect(n);
    correct(n);
}