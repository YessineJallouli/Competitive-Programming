//100%
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m; cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    map<string, set<int>> pr;
    map<string, set<int>> sf;
    for (int i = 0; i < n; i++) {
        string t;
        for (char c : s[i]) {
            t+= c;
            if (t.size() >= 3) {
                pr[t].insert(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string t;
        for (int j = (int) s[i].size()-1; j >= 0; j--) {
            t = s[i][j]+t;
            if (t.size() >= 3) {
                sf[t].insert(i);
            }
        }
    }


    for (int i = 0; i < m; i++) {
        string t; cin >> t;
        int z = (int) t.size();
        int nbOk = 0;
        set<pair<int,int>> res;
        for (int j = 3; j < z && res.size() < 2; j++) {
            string s1 = t.substr(0,j);
            string s2 = t.substr(j,z-j);
            
            if (pr.count(s1) && sf.count(s2)) {
                if (pr[s1].size() == 1 && sf[s2].size() == 1) {
                    res.insert({*pr[s1].begin(), *sf[s2].begin()});
                } else if (!pr[s1].empty() && !sf[s2].empty()) {
                    nbOk = 2;
                }
            }

            s2 = t.substr(j-1,z-j+1);
            if (pr.count(s1) && sf.count(s2)) {
                if (pr[s1].size() == 1 && sf[s2].size() == 1) {
                    res.insert({*pr[s1].begin(), *sf[s2].begin()});
                } else if (!pr[s1].empty() && !sf[s2].empty()) {
                    nbOk = 2;
                }
            }
        }

        if (nbOk == 0 && res.size() == 1)
            nbOk = 1;

        if (nbOk == 0)
            cout << "none\n";
        else if (nbOk == 2 || res.size() > 1)
            cout << "ambiguous\n";
        else {
            cout << s[(*res.begin()).first] << ' ' << s[(*res.begin()).second] << '\n';
        }
    }
}
