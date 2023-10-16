#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int nb = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]%2)
                nb++;
        }
        cout << min(nb, n-nb) << '\n';
    }
}