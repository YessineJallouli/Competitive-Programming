#include <bits/stdc++.h>
using namespace std;

bool canSplit(int n, int x) {
    if (x-1 > n)
        return false;
    /// n = a*x + b*(x-1) ?  with a,b >= 0
    /// n = a*x + b*x -b;
    /// n = (a+b)*x - b;
    int nb = n/x*x;
    if (n%x)
        nb+=x;
    int coeff = nb/x;
    if (nb-n > coeff)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int occ[n+1];
        memset(occ, 0, sizeof occ);
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            occ[x]++;
            s.insert(x);
        }
        set<int> freq;
        for (int i : s)
            freq.insert(occ[i]);
        int res = INT_MAX;
        for (int i = 1; i <= *freq.begin()+1; i++) {
            bool can = true;
            int ans = 0;
            for (int f: freq) {
                if (!canSplit(f, i))
                    can = false;
            }
            if (can || i == 2) {
                for (int j : s) {
                    ans+= (occ[j]+(i-1))/i;
                }
                res = min(res, ans);
            }
        }
        cout << res << '\n';
    }
}