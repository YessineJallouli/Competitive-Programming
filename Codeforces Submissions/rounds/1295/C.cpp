#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string s,t; cin >> s >> t;
        vector<int> pos[26];
        for (int i = 0; i < s.size(); i++) {
            int p = s[i]-'a';
            pos[p].push_back(i);
        }
        int curr = 0;
        int ans = 0;
        for (char c : t) {
            if (pos[c-'a'].size() == 0) {
                ans = -1; break;
            }
            if (curr == 0)
                ans++;
            int id = lower_bound(pos[c-'a'].begin(), pos[c-'a'].end(), curr) - pos[c-'a'].begin();
            if (id == pos[c-'a'].size()) {
                ans++;
                id = lower_bound(pos[c-'a'].begin(), pos[c-'a'].end(), 0) - pos[c-'a'].begin();
            }
            curr = pos[c-'a'][id]+1;
        }
        cout << ans << '\n';
    }
}