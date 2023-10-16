#include <bits/stdc++.h>
#define ll long long
#define Iceberg main
using namespace std;


int Iceberg() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        cout << a[n-1]-a[0] << '\n';
    }
}