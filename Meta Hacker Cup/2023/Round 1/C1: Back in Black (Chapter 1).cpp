#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

const int N = 4e6+7;
int a[N];

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i <= n; i++)
        a[i] = 0;

    int q; cin >> q;
    map<int,int> cnt;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cnt[x]++;
        cnt[x]%= 2;
    }

    for (auto [x,y] : cnt) {
        if (y == 0)
            continue;
        for (int i = x; i <= n; i+= x)
            a[i]++;
    }

    for (int i = 0; i < n; i++) {
        if (a[i+1]%2 == 1) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
    }
    for (int i = 0; i <= n; i++)
        a[i] = 0;
    int nb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (a[i+1]%2 == 1) {
                s[i] = '0';
            }
            else {
                s[i] = '0';
                nb++;
                for (int j = i+1; j <= n; j+= i+1) {
                    a[j]++;
                }
            }
        }
        else {
            if (a[i+1]%2 == 1) {
                s[i] = '0';
                nb++;
                for (int j = i+1; j <= n; j+= i+1) {
                    a[j]++;
                }
            }
        }
    }
    cout << nb << '\n';
}

int main() {
    SaveTime
    freopen("back_in_black_chapter_1_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}