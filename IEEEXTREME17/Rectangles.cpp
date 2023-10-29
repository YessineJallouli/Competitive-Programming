//12%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

int main() {
    SaveTime
    int p,q; cin >> p >> q;
    vector<int> v;
    int h = p;
    int sum = 0;
    while (h <= q) {
        if (isPrime(h) && h != 2 && h != 3) {
            v.push_back(h);
            sum+= h;
        }
        h++;
    }
    int sz = v.size();
    vector<vector<pair<int,int>>> div(sz);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j*j <= v[i]; j++) {
            if (v[i]%j == 0) {
                div[i].emplace_back(j, v[i]/j);
                div[i].emplace_back(v[i]/j, j);
            }
        }
    }
    int db = q;
    if (db%2 == 0)
        db--;
    for (int i = db; i >= p; i-= 2) {
        // add i ?
        vector<pair<int,int>> dv;
        for (int j = 1; j*j <= i; j++) {
            if (i%j == 0) {
                dv.emplace_back(j, i/j);
                dv.emplace_back(i/j, j);
            }
        }
        bool ok = true;
        for (int x = 0; x < v.size(); x++) {
            for (auto [a,b]: div[x]) {
                for (auto [c,d]: dv) {
                    if (__gcd(a, c) != 1 || __gcd(a, d) != 1 || __gcd(b, c) != 1 || __gcd(b, d) != 1)
                        ok = false;
                }
            }
        }
        if (ok) {
            sum+= i;
            v.push_back(i);
            div.push_back(dv);
        }
    }

    db = q-q%2;

    for (int i = db; i >= p; i-= 2) {
        // add i ?
        vector<pair<int,int>> dv;
        for (int j = 1; j*j <= i; j++) {
            if (i%j == 0) {
                dv.emplace_back(j, i/j);
                dv.emplace_back(i/j, j);
            }
        }
        bool ok = true;
        for (int x = 0; x < v.size(); x++) {
            for (auto [a,b]: div[x]) {
                for (auto [c,d]: dv) {
                    if (__gcd(a, c) != 1 || __gcd(a, d) != 1 || __gcd(b, c) != 1 || __gcd(b, d) != 1)
                        ok = false;
                }
            }
        }
        if (ok) {
            sum+= i;
            v.push_back(i);
            div.push_back(dv);
        }
    }
    cout << sum;
}
