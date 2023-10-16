#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        map<int,int> nb;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            nb[a[i]]++;
        }
        bool ans = true;
        for (int i = 0; i <n; i++) {
            if (nb[a[i]] == 1) {
                ans = false;
            }
        }
        if (! ans) {
            cout << -1 << '\n';
        }
        else {
            int lst = 0;
            for (int i = 0; i < n-1; i++) {
                if (a[i] != a[i+1]) {
                    for (int j = lst+1; j <= i; j++) {
                        cout << j+1 << ' ';
                    }
                    cout << lst+1 << ' ';
                    lst = i+1;
                }
            }
            for (int i = lst+1; i <= n-1; i++) {
                cout << i+1 << ' ';
            }
            cout << lst+1 << ' ';
            cout << '\n';
        }
    }
}