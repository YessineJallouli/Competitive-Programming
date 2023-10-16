#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5;

ll tree[4*N];

ll mrg(ll x, ll y) {
    return x+y;
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
    if (ns > qe || ne < qs) {
        return 0; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = N-1) {
    if (pos > ne || pos < ns)
        return;
    if (ns == ne) {
        tree[id] += val;
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(pos, val, l, ns, md);
    upd(pos, val ,r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

bool match(string &s, string &ch) {
    int n = (int) s.size();
    /// Prefix function
    vector<int> pr(n);
    pr[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pr[i-1];
        while (j > 0 && s[j] != s[i])
            j = pr[j-1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    /// Pattern matching
    bool ans = false;
    int j = 0;
    for (int i = 0; i < (int) ch.size(); i++) {
        while (j > 0 && ch[i] != s[j])
            j = pr[j-1];
        if (ch[i] == s[j])
            j++;
        if (j == n)
            ans = true;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("curse.in", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s1,s2; cin >> s1 >> s2;
        int n1 = (int) s1.size();
        for (int i = 0; i < 4*N; i++) {
            tree[i] = 0;
        }

        vector<pair<int,int>> segments;

        for (int i = 0; i < n1; i++) {
            int l = i, r = n1-1;
            int ans = -1;
            while (l <= r) {
                int m = (l+r)/2;
                int nb = m-i+1;
                string pattern = s1.substr(i,nb);
                if (match(pattern,s2)) {
                    ans = m;
                    l = m+1;
                }
                else {
                    r = m-1;
                }
            }
            if (ans != -1) {
                for (int j = i; j <= ans; j++) {
                    segments.emplace_back(j,i);
                }
            }
        }
        sort(segments.begin(), segments.end());

        int q; cin >> q;
        vector<tuple<int,int,int>> qr(q);
        for (int i = 0; i < q; i++) {
            int a,b; cin >> a >> b;
            qr[i] = {b,a,i};
        }
        sort(qr.begin(), qr.end());
        ll ans[q];
        int idx = 0;
        for (int i = 0; i < q; i++) {
            auto [b,a,id] = qr[i];
            a--; b--;
            while (idx != segments.size() && segments[idx].first <= b) {
                upd(segments[idx].second, 1);
                idx++;
            }
            ans[id] = get(a, b);
        }
        cout << "Case " << t << ":\n";
        for (int i = 0; i < q; i++) {
            cout << ans[i] << '\n';
        }
    }
}