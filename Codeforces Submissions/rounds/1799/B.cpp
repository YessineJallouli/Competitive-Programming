#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int nbO = 0;
        int nbS = 0;
        bool S = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == a[0])
                nbS++;
            if (a[i] == 1)
                nbO++;
        }
        if (nbO < n && nbO != 0) {
            cout << -1 << '\n';
        }
        else if (nbO == n || nbS == n) {
            cout << 0 << '\n';
        }
        else {
            int token = -1;
            vector<pair<int,int>> ans;
            while (token == -1 || a[token] != 2) {
                for (int i = 0; i < n - 1; i++) {
                    if (a[i] != a[i + 1]) {
                        token = i;
                        while (a[i] != 2 && a[i + 1] != 2 && a[i] != a[i + 1]) {
                            if (a[i] < a[i + 1]) {
                                token = i - 1;
                                a[i + 1] = (a[i + 1] + a[i] - 1) / a[i];
                                ans.emplace_back(i + 1, i);
                            } else {
                                a[i] = (a[i] + a[i + 1] - 1) / a[i + 1];
                                ans.emplace_back(i, i + 1);
                            }
                        }
                        if (a[i] == 2 || a[i + 1] == 2) {
                            if (a[i] == 2)
                                token = i;
                            else
                                token = i + 1;
                            break;
                        }
                    }
                }
                bool s = true;
                for (int i = 0; i < n; i++) {
                    if (a[i] != a[0])
                        s = false;
                }
                if (s) {
                    S = true;
                    break;
                }
            }
            if (! S) {
                for (int i = 0; i < n; i++) {
                    if (i == token)
                        continue;
                    while (a[i] != 2) {
                        ans.emplace_back(i, token);
                        a[i] = (a[i] + 1) / 2;
                    }
                }
            }
            cout << ans.size() << '\n';
            for (auto [a,b] : ans) {
                cout << a+1 << ' ' << b+1 << '\n';
            }
        }
    }
}