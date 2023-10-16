#include <bits/stdc++.h>
#define ll long long
#define Iceberg main
using namespace std;


int Iceberg() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        map<string, pair<int,int>> mp;
        int n,m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                string ch = s.substr(j, 2);
                if (ch.size() == 2)
                    mp[ch] = {i+1,j+1};
                ch = s.substr(j, 3);
                if (ch.size() == 3)
                    mp[ch] = {i+1,j+1};
            }
        }
        bool reach[m+1];
        memset(reach, 0, sizeof reach);
        string s; cin >> s;
        reach[0] = true;
        pair<int,int> a = {0,0};
        for (int i = 0; i < m; i++) {
            if (! reach[i])
                continue;
            string s1 = s.substr(i,2);
            if (s1.size() == 2) {
                if (mp[s1] != a)
                    reach[i+2] = true;
            }
            s1 = s.substr(i, 3);
            if (s1.size() == 3) {
                if (mp[s1] != a) {
                    reach[i+3] = true;
                }
            }
        }
        if (reach[m]) {
            vector<tuple<int,int,int>> ans;
            int id = m;
            while (id != 0) {
                if (id-2 >= 0 && reach[id-2]) {
                    string ch = s.substr(id-2, 2);
                    pair<int,int> k = mp[ch];
                    ans.push_back({k.second, k.second+1, k.first});
                    id-= 2;
                }
                else if (id-3 >= 0) {
                    string ch = s.substr(id-3, 3);
                    pair<int,int> k = mp[ch];
                    ans.push_back({k.second, k.second+2, k.first});
                    id-= 3;
                }
            }
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for (auto [a,b,c] : ans)
                cout << a << ' ' << b << ' ' << c << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}