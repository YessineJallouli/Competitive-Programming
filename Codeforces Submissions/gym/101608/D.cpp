#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int fr[N];

int main() {
    freopen("cases.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int nbOdd = 0;
            for (int j = i; j < n; j++) {
                fr[a[j]]++;
                if (fr[a[j]]%2 == 1) {
                    nbOdd++;
                }
                else
                    nbOdd--;
                if (nbOdd == 1) {
                    ans++;
                }
            }
            for (int j = i; j < n; j++) {
                fr[a[j]]--;
            }
        }
        cout << ans << '\n';
    }
}