#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
    int n; cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= 3979)
            s+= x;
    }
    cout << s;
}