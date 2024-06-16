#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int) s.size();
        int idx; cin >> idx;
        idx--;
        string ch;
        for (int i = 0; i < n; i++) {
            if (i != idx-1 && i != idx+1)
                ch+= s[i];
        }
        sort(ch.begin(), ch.end());
        if (idx) {
            ch.insert(idx-1, 1, s[idx-1]);
        }
        if (idx != n-1) {
            ch.insert(idx+1, 1, s[idx+1]);
        }
        cout << ch << '\n';
    }
}
