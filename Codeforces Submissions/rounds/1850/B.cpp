#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        vector<pair<int,int>> v;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            if (a <= 10)
                v.emplace_back(b,i+1);
        }
        sort(v.rbegin(), v.rend());
        cout << v[0].second << '\n';
    }
}