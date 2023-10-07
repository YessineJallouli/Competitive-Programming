#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

const int N = 4e6+7;
int a[N];

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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i <= n; i++) {
        a[i] = 0;
        tree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (a[i+1]%2 == 1) {
                s[i] = '0';
            }
            else {
                upd(i+1, 1);
                s[i] = '0';
                for (int j = i+1; j <= n; j+= i+1) {
                    a[j]++;
                }
            }
        }
        else {
            if (a[i+1]%2 == 1) {
                upd(i+1, 1);
                s[i] = '0';
                for (int j = i+1; j <= n; j+= i+1) {
                    a[j]++;
                }
            }
        }
    }
    int q; cin >> q;
    ll ans = 0;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int k = get(x) - get(x-1);
        if (k == 1)
            upd(x, -1);
        else
            upd(x, 1);
        ans+= get(n);
    }
    cout << ans << '\n';
}

int main() {
    SaveTime
    freopen("back_in_black_chapter_2_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}