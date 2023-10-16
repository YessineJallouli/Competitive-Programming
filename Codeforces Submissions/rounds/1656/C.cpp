#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        bool one = false;
        bool zero = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1)
                one = true;
            if (a[i] == 0)
                zero = true;
        }
        if (one && zero)
            cout << "NO\n";
        else if (one) {
            bool ans = true;
            sort(a, a+n);
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i-1]+1)
                    ans = false;
            }
            cout << (ans ? "YES\n" : "NO\n");
        }
        else
            cout << "YES\n";
    }
}