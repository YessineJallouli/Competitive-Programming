#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
int tree[N];

void upd(int x, int val) {
    for (; x < N; x += x&(-x))
        tree[x]+= val;
}

int get(int x) {
    int res = 0;
    for (; x; x-= x&(-x))
        res+= tree[x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        long long ans = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x++;
            a[i] = x;
            ans+= get(N-1) - get(x-1);
            upd(x, 1);
        }
        for (int i = 0; i < n; i++) {
            upd(a[i], -1);
        }
        cout << ans << '\n';
    }
}