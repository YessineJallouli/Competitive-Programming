#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ask(int n) {
    cout << "? " << n << endl;
    int x; cin >> x;
    return x;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int vis[n+1];
        memset(vis, false, sizeof vis);
        int ans[n+1];
        for (int i = 0; i <= n; i++)
            ans[i] = i;
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            while (true) {
                int x = ask(i);
                if (vis[x])
                    break;
                vis[x] = true;
                v.push_back(x);
            }
            for (int i = 0; i < (int) v.size()-1; i++) {
                int a = v[i];
                int b = v[i+1];
                swap(ans[a], ans[b]);
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}