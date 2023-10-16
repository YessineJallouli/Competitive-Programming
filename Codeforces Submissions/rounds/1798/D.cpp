#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        bool ans = false;
        int mx = 0, mn = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
            if (a[i] != 0)
                ans = true;
        }
        if (ans) {
            cout << "Yes\n";
            int s = mx-mn;
            ll prSum = 0;
            sort(a, a+n);
            deque<int> q;
            for (int i = 0; i < n; i++)
                q.push_back(a[i]);
            for (int i = 0; i < n; i++) {
                if (abs(prSum+q.back()) < s) {
                    prSum+= q.back();
                    cout << q.back() << ' ';
                    q.pop_back();
                }
                else {
                    prSum+= q[0];
                    cout << q[0] << ' ';
                    q.pop_front();
                }
            }
            cout << '\n';
        }
        else {
            cout << "No\n";
        }
    }
}