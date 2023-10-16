#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int occ[n+1];
        memset(occ, 0, sizeof occ);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            occ[a[i]]++;
        }
        vector<int> b;
        int i = 0;
        while (i < n) {
            int d = 0;
            while (occ[d] > 0)
                d++;
            set<int> s;
            while (s.size() != d) {
                occ[a[i]]--;
                if (a[i] < d)
                    s.insert(a[i]);
                i++;
            }
            if (! d)
                i++;
            b.push_back(d);
        }
        cout << b.size() << '\n';
        for (int i : b)
            cout << i << ' ';
        cout << '\n';
    }
}