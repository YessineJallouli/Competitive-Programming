#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool can_go(string &s, int a, int b) {
    vector<int> portal;
    int n = (int) s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'o')
            portal.push_back(i);
    }

    bool vis[n];
    memset(vis, false, sizeof vis);
    vector<int> v = {a};
    bool ans = false;
    bool first_time = true;

    while (! v.empty()) {
        for (int i : v) {
            vis[i] = true;
            if (i == b)
                ans = true;
        }

        vector<int> aux;
        for (int i : v) {
            if (i != 0) {
                if (! vis[i-1] && s[i-1] != '#') {
                    aux.push_back(i-1);
                }
            }
            if (i != n-1) {
                if (! vis[i+1] && s[i+1] != '#') {
                    aux.push_back(i+1);
                }
            }
            if (s[i] == 'o' && first_time) {
                first_time = false;
                for (int j : portal) {
                    if (! vis[j])
                        aux.push_back(j);
                }
            }
        }
        v.swap(aux);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("portals.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n; string s; cin >> n >> s;
        int a,b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 's')
                a = i;
            if (s[i] == 'e')
                b = i;
        }
        bool cant = false;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'e' && s[i+1] == 's')
                cant = true;
            if (s[i] == 's' && s[i+1] == 'e')
                cant = true;
        }
        if (a > b)
            swap(a,b);
        bool adjA = false, adjB = false;
        if (a != 0 && s[a-1] == 'o')
            adjA = true;
        if (s[a+1] == 'o')
            adjA = true;
        if (s[b-1] == 'o')
            adjB = true;
        if (b != n-1 && s[b+1] == 'o')
            adjB = true;
        if ((adjB && adjA) || cant) {
            cout << -1 << '\n';
            continue;
        }
        if (! can_go(s, a,b)) {
            cout << 0 << '\n';
        }
        else {
            vector<int> v;

            for (int i = a+1; i < n; i++) {
                if (s[i] == '.') {
                    v.push_back(i);
                    break;
                }
            }

            for (int i = a-1; i >= 0; i--) {
                if (s[i] == '.') {
                    v.push_back(i);
                    break;
                }
            }

            for (int i = b+1; i < n; i++) {
                if (s[i] == '.') {
                    v.push_back(i);
                    break;
                }
            }
            for (int i = b-1; i >= 0; i--) {
                if (s[i] == '.') {
                    v.push_back(i);
                    break;
                }
            }
            bool one = false;
            for (int i : v) {
                string ch = s;
                ch[i] = '#';
                if (!can_go(ch, a, b))
                    one = true;
            }
            if (one) {
                cout << 1 << '\n';
            }
            else {
                cout << 2 << '\n';
            }
        }
    }
}