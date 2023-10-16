#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        n*= 2;
        int x; cin >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        bool ans = true;
        for (int i = 0; i < n/2; i++) {
            if (a[i+n/2]-a[i] < x) {
                ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}