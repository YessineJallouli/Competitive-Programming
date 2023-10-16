#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long pcm(ll a, ll b) {
    return a*b / __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        vector<vector<int>> cycles;
        bool visit[n+1];
        memset(visit, false, sizeof visit);
        for (int i = 0; i < n; i++) {
            int a = p[i];
            vector<int> v;
            while (true) {
                if (visit[a])
                    break;
                v.push_back(a);
                visit[a] = true;
                a = p[a-1];
            }
            if (v.size()) {
                cycles.push_back(v);
            }
        }
        long long ans = 1;
        for (auto &i : cycles) {
            deque<char> initial;
            deque<char> rot;
            for (int j : i) {
                initial.push_back(s[j-1]);
                rot.push_back(s[j-1]);
            }
            long long nb = 0;
            for (int k = 0; k < initial.size(); k++) {
                char c = rot.back();
                rot.pop_back();
                rot.push_front(c);
                bool ok = true;
                for (int l = 0; l < initial.size(); l++) {
                    if (rot[l] != initial[l])
                        ok = false;
                }
                if (ok) {
                    nb = k+1;
                    break;
                }
            }
            ans = pcm(ans, nb);
        }
        cout << ans << '\n';
    }
}