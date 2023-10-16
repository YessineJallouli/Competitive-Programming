#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        deque<int> a(n);
        deque<int> b(m);
        string x,y; cin >> x >> y;
        if (m > n)  {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            a[i] = x[i]-'0';
        }
        for (int i = 0; i < m; i++) {
            b[i] = y[i]-'0';
        }
        for (int i = 0; i < n; i++) {
            if ((int) a.size() == (int) b.size())
                break;
            if (a[0] == b[0] || a[1] == b[0]) {
                a.pop_front();
                a.pop_front();
                a.push_front(b[0]);
            }
            else {
                a.pop_front();
            }
        }
        bool ans = true;
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i])
                ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

}