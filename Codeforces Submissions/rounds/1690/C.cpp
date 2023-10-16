#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout << b[0]-a[0] << ' ';
        for (int i = 1; i < n; i++) {
            if (a[i] > b[i-1]) {
                cout << b[i]-a[i] << ' ';
            }
            else {
                cout << b[i]-b[i-1] << ' ';
            }
        }
        cout << '\n';
    }
}