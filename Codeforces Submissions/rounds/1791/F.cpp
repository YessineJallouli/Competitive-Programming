#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 7;
int tree[N], a[N];
int n;

// Fenwick tree is used only for sum and xor (I guess)

int f(int x) {
    int ans = 0;
    while (x) {
        ans+= x%10;
        x/= 10;
    }
    return ans;
}

void upd(int x, int val) {
    for (; x <= n; x += x&(-x))
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
        int q; cin >> n >> q;
        for (int i = 0; i <= n+1; i++)
            tree[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i+1];
        }
        while (q--) {
            int t; cin >> t;
            if (t == 1) {
                int l,r; cin >> l >> r;
                upd(l, 1);
                upd(r+1, -1);
            }
            else {
                int x; cin >> x;
                int h = min(3,get(x));
                int l = a[x];
                while (h--) {
                    l = f(l);
                }
                cout << l << '\n';
            }
        }
    }
}