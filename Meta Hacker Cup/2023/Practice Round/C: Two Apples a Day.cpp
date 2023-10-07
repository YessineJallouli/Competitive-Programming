#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int solve1(vector<int> &v, int k) {
    multiset<int> m;
    for (int i : v) {
        m.insert(i);
    }
    int add = 0;
    int res = INT_MAX;
    while (! m.empty()) {
        int n1 = *m.begin();
        int n2 = k-n1;
        m.erase(m.begin());
        if (m.count(n2)) {
            m.erase(m.find(n2));
        }
        else {
            if (n2 <= 0)
                return INT_MAX;
            add++;
            res = max(-1,n2);
        }
    }
    if (add != 1)
        return INT_MAX;
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(2*n-1);
    for (int i = 0; i < 2*n-1; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    int k = min({solve1(a,a[0]+a.back()), solve1(a,a[0]+a[2*n-3]),solve1(a, a[1]+a.back())});
    if (k == INT_MAX)
        cout << -1 << '\n';
    else
        cout << k << '\n';
}

int main() {
    SaveTime
    freopen("two_apples_a_day_input1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}
