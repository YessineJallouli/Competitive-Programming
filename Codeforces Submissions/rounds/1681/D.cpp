#include <bits/stdc++.h>
using namespace std;

int sz(long long n) {
    int nb = 0;
    while (n) {
        n/= 10; nb++;
    }
    return nb;
}

int solve() {
    int n; long long x;
    cin >> n >> x;
    vector<long long> q = {x};
    map<long long, bool> vis;
    int op = 0;
    while (! q.empty()) {
        vector<long long> q1;
        for (long long val : q) {
            if (sz(val) == n)
                return op;
            long long v = val;
            while (v) {
                long long newV = val*(v%10);
                if (! vis.count(newV) && newV) {
                    q1.push_back(newV);
                    vis[newV] = true;
                }
                v/= 10;
            }
        }
        op++;
        q1.swap(q);
    }
    return -1;
}

int main()
{
    cout << solve();
}