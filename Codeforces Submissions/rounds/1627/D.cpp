#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N=  1e6+7;
int vis[N];
int a[N];

int main() {
    SaveTime
    int n; cin >> n;
    int nb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    for (int i = 1; i < N; i++) {
        vector<int> v;
        if (vis[i])
            continue;
        for (int j = i; j < N; j+= i) {
            if (vis[j]) {
                v.push_back(j);
            }
        }
        if (v.size() == 0)
            continue;
        for (int j = 0; j < v.size(); j++) {
            v[j]/= i;
        }
        int g = v[0];
        for (int j = 0; j < v.size(); j++) {
            g = __gcd(v[j], g);
        }
        if (g == 1) {
            vis[i] = true;
            nb++;
        }
    }
    cout << nb;
}