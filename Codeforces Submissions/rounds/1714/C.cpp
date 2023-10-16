#include <bits/stdc++.h>
using namespace std;

vector<int> v;
bool used[10];

int ans = INT_MAX;

void solve(int n, int nb) {
    if (n == 0) {
        ans = min(ans, nb);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (used[i])
            continue;
        used[i] = true;
        solve(n-i, nb*10+i);
        used[i] = false;
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int s; cin >> s;
        ans = INT_MAX;
        solve(s, 0);
        cout << ans << '\n';
    }
}