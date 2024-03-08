#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
int ghorbel[10000001];
 
 
void sieve() {
    for (int i = 2; i <= 10000000; i++) {
        if (!ghorbel[i]) {
            for (int j = i; j <= 10000000; j += i) {
                if (!ghorbel[j]) ghorbel[j] = i;
            }
        }
    }
}
 
 
int main() {
    sieve();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
 
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] != b[i]) {
                if (a[i] > b[i]) {
                    a[i]/=ghorbel[a[i]];
                }
                else {
                    b[i]/= ghorbel[b[i]];
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
 
}
