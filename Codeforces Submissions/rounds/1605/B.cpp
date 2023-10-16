#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    //SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<vector<int>> ans;
        while (true) {
            bool b = true;
            //cout << s << '\n';
            for (int i = 0; i < n-1; i++) {
                if (s[i] > s[i+1])
                    b = false;
            }
            if (b)
                break;
            int i = 0, j = n-1;
            vector<int> v1;
            vector<int> v2;

            while (i < j) {
                while (s[j] != '0') {
                    j--;
                    if (j <= i)
                        break;
                }
                if (j <= i)
                    break;
                while (s[i] != '1') {
                    i++;
                    if (j <= i)
                        break;
                }
                if (j <= i)
                    break;
                v1.push_back(i);
                v2.push_back(j);
                i++;
                j--;
            }
            vector<int> vv;
            for (int i : v1) {
                s[i] = '0';
                vv.push_back(i);
            }
            reverse(v2.begin(), v2.end());
            for (int i : v2) {
                s[i] = '1';
                vv.push_back(i);
            }
            ans.push_back(vv);
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].size() << ' ';
            for (int j : ans[i])
                cout << j+1 << ' ';
            cout << '\n';
        }
    }
}