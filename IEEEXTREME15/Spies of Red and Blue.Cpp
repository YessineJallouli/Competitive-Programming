#include <bits/stdc++.h>
using namespace std;
#define ll long long

int val(string str){
    int l=str.length();
    str = str.substr(1,l-1);
    return stoi(str);
}

const int N = 2005;
vector<set<int>> tree(N);
vector<set<int>> invtree(N);

int ans = INT_MAX;

void dfs(int node, int par, int dest, int nb) {
    if (dest == node) {
        ans = nb;
    }
    for (int i : invtree[node]) {
        if (i == par)
            continue;
        dfs(i, node, dest, nb+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n1,n2,q; cin >> n1 >> n2 >> q;
        for (int i = 0; i < N; i++) {
            tree[i].clear();
            invtree[i].clear();
        }
        for (int i = 2; i <= n1; i++) {
            string s; cin >> s;
            int x = val(s);
            if (s[0] == 'B')
                x+= n1;
            tree[i].insert(x);
            invtree[x].insert(i);
        }
        for (int i = 2; i <= n2; i++) {
            string s; cin >> s;
            int x = val(s)+n1;
            if (s[0] == 'R')
                x-= n1;
            tree[n1+i-1].insert(x);
            invtree[x].insert(n1+i-1);
        }
        while (q--) {
            char c; cin >> c;
            if (c == 'c') {
                string s1, s2; cin >> s1 >> s2;
                int x1 = val(s1), x2 = val(s2);
                if (s1[0] == 'R' && s2[0] == 'R') {
                    int nb1 = *tree[x1].begin();
                    invtree[nb1].erase(x1);
                    invtree[x2].insert(x1);
                    tree[x1].clear();
                    tree[x1].insert(x2);

                }
                else if (s1[0] == 'R' && s2[0] == 'B') {
                    int nb1 = *tree[x1].begin();
                    invtree[nb1].erase(x1);
                    invtree[x2+n1].insert(x1);
                    tree[x1].clear();
                    tree[x1].insert(x2+n1);
                }
                else if (s1[0] == 'B' && s2[0] == 'R') {
                    int nb1 = *tree[x1+n1].begin();
                    invtree[nb1].erase(x1+n1);
                    invtree[x2].insert(x1+n1);
                    tree[x1+n1].clear();
                    tree[x1+n1].insert(x2);
                }
                else {
                    int nb1 = *tree[x1+n1].begin();
                    invtree[nb1].erase(x1+n1);
                    invtree[x2+n1].insert(x1+n1);
                    tree[x1+n1].clear();
                    tree[x1+n1].insert(x2+n1);
                }
            }
            else {
                string s1, s2; cin >> s1 >> s2;
                int x1 = val(s1), x2 = val(s2);
                int ans1 = INT_MAX, ans2 = INT_MAX;
                dfs(1, -1, x1,0);
                ans1 = min(ans1,ans);
                ans = INT_MAX;
                dfs(n1+1, -1, x1, 0);
                ans2 = min(ans, ans2);
                ans = INT_MAX;
                dfs(1, -1, x2+n1,0);
                ans1 = min(ans1, ans);
                ans = INT_MAX;
                dfs(n1+1, -1, x2+n1, 0);
                ans2 = min(ans, ans2);
                ans = INT_MAX;
                //cout << ans1 << ' ' << ans2 << '\n';
                if (ans1 == INT_MAX && ans2 == INT_MAX) {
                    cout << "NONE\n";
                }
                else if (ans1 == ans2) {
                    cout << "TIE " << ans1 << "\n";
                }
                else if (ans1 < ans2) {
                    cout << "RED " << ans1 << '\n';
                }
                else {
                    cout << "BLUE " << ans2 << '\n';
                }
            }
        }
    }
}
