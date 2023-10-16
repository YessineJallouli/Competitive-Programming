#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int a[n];
        memset(a, -1, sizeof a);
        set<int> r;
        int l = n;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (r.count(x))
                continue;
            r.insert(x);
            if (l == 0)
                continue;
            a[l-1] = i+1;
            l--;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
}