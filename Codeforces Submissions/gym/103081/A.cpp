#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main(){
    SaveTime
    int n,k; cin >> n >> k; cin.ignore();
    vector<tuple<int,int,string>> v;
    map<string, int> nb;
    set<string> m;
    string a[3*n];
    for (int i = 0; i < 3*n; i++) {
        string s; getline(cin, s);
        a[i] = s;
        nb[s]++;
        m.insert(s);
    }
    map<string, bool> vs;
    for (int i = 3*n-1; i >= 0; i--) {
        if (vs[a[i]])
            continue;
        vs[a[i]] = true;
        v.push_back({nb[a[i]], i, a[i]});
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < k && i < v.size(); i++) {
        cout << get<2>(v[i]) << '\n';
    }
}