//100%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int n; cin >> n;
    vector<tuple<string,string,string>> s(n);
    map<string, bool> know;
    set<string> p;
    for (int i = 0; i < n; i++) {
        string s1,s2,s3; cin >> s1 >> s2 >> s3;
        p.insert(s1);
        p.insert(s3);
        s[i] = {s1,s2,s3};
        if (s2[0] == '-') {
            know[s3] = true;
        }
    }

    while (true) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            auto [s1, s2, s3] = s[i];
            if (s2 == "??" && know.count(s1)) {
                ok = true;
                know[s3] = true;
                s2 = "--";
                get<1>(s[i]) = s2;
            }
            else if (s2 == "??" && know.count(s3)) {
                ok = true;
                know[s1] = true;
                s2 = "--";
                get<1>(s[i]) = s2;
            }
        }
        if (! ok)
            break;
    }
    for (auto [a,b] : know)
        p.erase(a);
    for (string ans : p) {
        cout << ans << '\n';
    }
}
