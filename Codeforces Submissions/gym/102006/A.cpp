#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    freopen("hello.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int a[12];
        for (int i = 0; i < 12; i++) {
            cin >> a[i];
        }
        bool ans = true;
        for(int i = 0; i < 3; i++) {
            if (a[i] >= a[i+1])
                ans = false;
        }
        for (int i = 4; i < 12; i++) {
            if (a[i] <= a[3])
                ans = false;
        }
        cout << (ans ? "yes\n" : "no\n");
    }
}