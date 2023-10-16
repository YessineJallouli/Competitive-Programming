#include <bits/stdc++.h>
#define ll long long
using namespace std;

char ask1(int i) {
    cout << "? 1 " << i << endl;
    char x; cin >> x;
    return x;
}

int ask2(int l, int r) {
    cout << "? 2 " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

string ans;

int differentChar(int l, int r) {
    int res = 0;
    bool vis[26];
    memset(vis, false, sizeof vis);
    for (int i = l; i <= r; i++) {
        if (vis[ans[i]-'a'])
            continue;
        vis[ans[i]-'a'] = true;
        res++;
    }
    return res;
}

int main() {
    int n; cin >> n;
    int nbDiff = 0;
    int occ[26];
    memset(occ, -1, sizeof occ);

    for (int i = 1; i <= n; i++) {
        int d = ask2(1,i);
        if (d > nbDiff) {
            char c = ask1(i);
            ans+= c;
            occ[c-'a'] = i;
            nbDiff = d;
        }
        else {
            vector<int> ids;
            for (int & j : occ) {
                if (j != -1)
                    ids.push_back(j);
            }
            sort(ids.begin(), ids.end());
            int idans = -1;
            int l = 0, r = (int) ids.size()-1;
            while (l <= r) {
                int m = (l+r)/2;
                int nb = ask2(ids[m],i);
                int df = differentChar(ids[m]-1,i-2);
                if (df == nb) {
                    idans = ids[m];
                    l = m+1;
                }
                else {
                    r = m-1;
                }
            }
            ans+= ans[idans-1];
            occ[ans.back()-'a'] = i;
        }
    }
    cout << "! " << ans;
}