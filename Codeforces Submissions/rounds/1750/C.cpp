// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; string a,b;
        cin >> n >> a >> b;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i] != '0')
                v.push_back(i);
        }
        if ((int) v.size()%2) {
            for (int i = 0; i < n; i++) {
                if (b[i] == '1')
                    b[i] = '0';
                else if (b[i] == '0')
                    b[i] = '1';
            }
        }
        for (int i : v) {
            if (b[i] == '1')
                    b[i] = '0';
                else if (b[i] == '0')
                    b[i] = '1';
        }
        sort(b.begin(), b.end());
        if (b[n-1] != b[0]) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            vector<pair<int,int>> ans;
            for (int i : v) {
                ans.emplace_back(i+1, i+1);
            }
            if (b[0] == '1') {
                ans.emplace_back(1,n);
                ans.emplace_back(1,1);
                ans.emplace_back(2,n);
            }
            cout << ans.size() << '\n';
            for (auto [l,r] : ans) {
                cout << l << ' ' << r << '\n';
            }
        }
    }
}