#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        vector<int> v;
        int nbP = 0;
        int nbN = 0;
        map<long long, bool> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]] = true;
            if (a[i] > 0) {
                nbP++;
            }
            else if (a[i] < 0) {
                nbN++;
            }
            if (a[i] != 0) {
                v.push_back(a[i]);
            }
        }
        if (nbP+nbN != n)
            v.push_back(0);
        if (nbP > 2 || nbN > 2) {
            cout << "NO\n";
            continue;
        }
        n = (int) v.size();
        bool ans = true;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    long long x = v[i]+v[j]+v[k];
                    if (! m[x])
                        ans = false;
                }
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}