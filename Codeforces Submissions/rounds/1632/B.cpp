#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
   // SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        n--;
        int b = -1;
        for (int bit = 25; bit >= 0; bit--) {
            if (n & (1<<bit)) {
                b = bit;
                break;
            }
        }
        vector<int> ans;
        while (n & (1 << b) && n) {
            ans.push_back(n);
            n--;
        }
        int t = 0;
        while (t <= n) {
            ans.push_back(t);
            t++;
        }
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}