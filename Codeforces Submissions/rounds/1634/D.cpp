#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;

int ask(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int x; cin >> x;
    return x;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 2; i < n; i++) {
            int x = ask(1, 2, i+1);
            v.push_back({x, i+1});
        }
        sort(v.rbegin(), v.rend());
        vector<pair<int, int>> v1;
        int sec = 1;
        for (int i = 1; i <= n; i++) {
            if (v[0].second == i || sec == i)
                continue;
            int x = ask(v[0].second,sec,i);
            v1.push_back({x, i});
        }
        sort(v1.rbegin(), v1.rend());
        int mx = max(v1[0].first, v[0].first);
        if (v1[n-3].first == v1[0].first && v[n-3].first == v[0].first) {
            if (v1[n-3].first > v[n-3].first) {
                cout << "! " << v[0].second << ' ' << sec << endl;
            }
            else
                cout << "! " << 1 << ' ' << 2 << endl;
            continue;
        }
        if (v1[n-3].first == v1[0].first && v1[0].first == mx) {
            cout << "! " << v[0].second << ' ' << sec << endl;
            continue;
        }
        if (v[n-3].first == v[0].first && v[0].first == mx) {
            cout << "! " << 1 << ' ' << 2 << endl;
            continue;
        }
        cout << "! " << v[0].second << ' ' << v1[0].second << endl;
    }
}