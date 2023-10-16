#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;

int d,h;

set<vector<int>> s;


map<vector<int>, ll> m;

set<ll> res;

ll solve(vector<int> &v) {
    vector<int> k;
    int s = 0;
    for (int i : v) {
        k.push_back(i);
        s+= i;
    }
    sort(k.begin(), k.end());
    if (k[0] < 0)
        return 0;
    if (k[d-1] == 1 && k[d-2] == 0)
        return 1;
    if (m.count(k))
        return m[k];

    ll ans = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        v[i]--;
        if (v[i] >= 0)
            ans = ans+solve(v);
        v[i]++;
    }
    if (s == h-1) {
        res.insert(ans);
    }
    return m[k] = ans;
}

void generate(int n) {
    if (n < 0)
        return;
    if (v.size() > d)
        return;
    if (n == 0) {
        if (v.size() == d)
            s.insert(v);
        return;
    }
    int b = 0;
    if (! v.empty())
        b = v.back();
    for (int i = b; i <= n; i++) {
        v.push_back(i);
        generate(n-i);
        v.pop_back();
    }
}

int main() {
    cin >> d >> h;
    generate(h-1);
    for (auto vec : s) {
        solve(vec);
    }
    res.insert(1);
    for (ll i : res)
        cout << i << '\n';
}