#include <bits/stdc++.h>
#define repeat(n) for (int i = 0; i < n; i++)
using namespace std;

bool solve(string &s) {
    bool ans = true;
    int n = s.size();
    vector<int> v;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < (int) v.size()-1; i++) {
        if (v[i] != v[i+1]-1)
            ans = false;
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        if (solve(t) || solve(s)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}