#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

void right_shift(vector<int> &v, int n) {
    vector<int> ans;
    for (int i = n; i < v.size(); i++) {
        ans.push_back(v[i]);
    }
    for (int i = 0; i < n; i++) {
        ans.push_back(v[i]);
    }
    v.swap(ans);
}

int main() {
    int T; cin >> T;
    //vector<int> v = {1};
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        int pos[n+1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            int id = pos[i];
            int nbShift = id-(i-1);
            if (nbShift < 0)
                nbShift+= a.size();
            ans.push_back(nbShift);
            right_shift(a, nbShift);
            a.pop_back();
            for (int j = 0; j < a.size(); j++) {
                pos[a[j]] = j;
            }
        }
        reverse(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}