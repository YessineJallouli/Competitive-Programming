#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i])
                ans = false;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                if (b[(i+1)%n] < b[i]-1)
                    ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}