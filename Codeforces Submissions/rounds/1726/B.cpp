#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        if (m < n) {
            cout << "NO\n";
            continue;
        }
        if (n%2 == 1) {
            cout << "YES\n";
            for (int i = 0; i < n-1; i++) {
                cout << 1 << ' ';
            }
            cout << m-n+1 << '\n';
        }
        else {
            if (m%2) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                if (n == m) {
                    for (int i = 0; i < n; i++)
                        cout << 1 << ' ';
                    cout << '\n';
                }
                else {
                    for (int i = 0; i < n-2; i++) {
                        cout << 1 << ' ';
                    }
                    cout << (m-(n-2))/2 << ' ' << (m-(n-2))/2 << '\n';
                }
            }
        }
    }
}