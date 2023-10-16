#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isSqrt(int n) {
    int k = sqrt(n);
    return (k*k == n);
}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (isSqrt(n+1)) {
            int sq = sqrt(n+1);
            cout << sq-1 << '\n';
            for (int i = 1; i < sq; i++) {
                cout << i << ' ';
            }
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}