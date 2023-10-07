#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

void solve() {
    int p; cin >> p;
    int P = p;
    int sum = 0;
    vector<int> v;
    for (int i = 2; i*i <= P; i++) {
        while (p%i == 0) {
            p/= i;
            v.push_back(i);
            sum+= i;
        }
    }
    if (p != 1) {
        sum += p;
        v.push_back(p);
    }
    if (sum > 41) {
        cout << -1 << '\n';
        return;
    }
    for (int i = sum; i < 41; i++)
        v.push_back(1);

    cout << v.size() << ' ';
    for (int i : v)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    SaveTime
    freopen("sum_41_chapter_1_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}