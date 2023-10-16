#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        set<int> s;
        map<int,int> nb;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
            nb[a[i]]++;
        }
        int prev = -1;
        int ansL = -1, ansR = -2;
        int currL = -1, currR = -1;
        for (int i : s) {
            if (i == prev+1 && nb[i] >= k) {
                currR = i; prev = i;
                if (ansR-ansL < currR-currL) {
                    ansR = currR;
                    ansL = currL;
                }
            }
            else if (nb[i] >= k) {
                currL = currR = prev = i;
                if (ansR-ansL < currR-currL) {
                    ansR = currR;
                    ansL = currL;
                }
            }
        }
        if (ansR == -2)
            cout << -1 << '\n';
        else
            cout << ansL << ' ' << ansR << '\n';
    }
}