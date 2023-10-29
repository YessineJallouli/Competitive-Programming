//25%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
vector<set<int>> graph(N);
int visited[N];
int t;
bool ans = false;
int dist[N];

ll dp[N];
int mod = 1e9+9;

void dfs(int node) {
    if (visited[node])
        return;
    visited[node] = true;
    if (dist[node] == 0) {
        dp[node] = 1;
        return;
    }
    for (int i : graph[node]) {
        if (dist[i] != -1 && dist[i] == dist[node]-1) {
            dfs(i);
            dp[node] = (dp[node]+dp[i])%mod;
        }
    }
}

int main() {
    SaveTime
    int c; cin >> c;
    while (c--) {
        ans = false;
        int n,h0,a,b,q; cin >> n >> t >> h0 >> a >> b >> q;
        string sss = to_string(t);
        if (sss.size() > n || t >= q) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0, r = q;
        int ans1 = -1; ll ans2 = -1;
        while (l <= r) {
            for (int i = 0; i <= q; i++) {
                dp[i] = 0;
                graph[i].clear();
            }
            int md = (l+r)/2;
            set<int> allowable;
            allowable.insert(h0);
            int p = h0;
            for (int i = 0; i < md; i++) {
                p = (a * p + b) % q;
                if (allowable.count(p))
                    break;
                allowable.insert(p);
            }
            set<int> allow;
            for (int i: allowable) {
                string s = to_string(i);
                while (s.size() > n) {
                    s.erase(0, 1);
                }
                int k = stoi(s);
                allow.insert(k);
            }
            allow.insert(t);
            allow.insert(0);
            for (int i = 0; i <= q; i++)
                graph[i].clear();
            for (int i = 0; i <= q; i++) {
                if (!allow.count(i))
                    continue;
                visited[i] = false;
                string s = to_string(i);
                while (s.size() < n)
                    s = '0' + s;
                for (int j = 0; j < n; j++) {
                    char h = s[j];
                    char m = s[j];
                    // add 1
                    if (h == '9')
                        h = '0';
                    else
                        h++;
                    s[j] = h;
                    int k = stoi(s);
                    if (allow.count(k)) {
                        graph[i].insert(k);
                    }
                    s[j] = m;
                    //sub 1
                    h = s[j];
                    if (h == '0')
                        h = '9';
                    else
                        h--;
                    s[j] = h;
                    k = stoi(s);
                    if (allow.count(k)) {
                        graph[i].insert(k);
                    }
                    s[j] = m;
                }
            }

            vector<int> v = {0};
            for (int i = 0; i < q; i++) {
                dist[i] = -1;
            }
            int nb = 0;
            while (!v.empty()) {
                for (int i: v) {
                    dist[i] = nb;
                }
                vector<int> aux;
                for (int i: v) {
                    for (int ch: graph[i]) {
                        if (dist[ch] == -1) {
                            dist[ch] = nb + 1;
                            aux.push_back(ch);
                        }
                    }
                }
                v.swap(aux);
                nb++;
            }
            for (int i = 0; i < q; i++)
                visited[i] = false;

            dfs(t);

            if (dist[t] != -1) {
                ans1 = dist[t]; ans2 = dp[t];
                r = md-1;
            }
            else {
                l = md+1;
            }
        }
        if (ans1 != -1) {
            cout << ans1 << ' ' << ans2 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}
