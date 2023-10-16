#include <bits/stdc++.h>
#define ll long long
#define Iceberg main
using namespace std;

int ask(int n) {
    cout << "+ " << n << endl;
    int x; cin >> x;
    return x;
}

int Iceberg() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x > n)
                x /= 2;
            a[i] = x;
        }
        bool visited[n + 1];
        memset(visited, false, sizeof visited);
        for (int i = 0; i < n; i++) {
            while (a[i] && visited[a[i]]) {
                a[i] /= 2;
            }
            visited[a[i]] = true;
        }
        bool can = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                can = false;
        }
        if (can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}