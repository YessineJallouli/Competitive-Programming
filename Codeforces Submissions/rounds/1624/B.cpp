#include <bits/stdc++.h>
#define ll long long
#define Iceberg main
using namespace std;


int Iceberg() {
    int T; cin >> T;
    while (T--) {
        vector<int> v;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            v.push_back(x);
        }
        int df1 = v[2]-v[1];
        int k = v[1]-df1;
        bool ans = false;
        if (k%v[0] == 0 && k>0)
            ans = true;
        int df2 = v[2]-v[0];
        if (df2%2 == 0) {
            df2/= 2;
            k = v[2]-df2;
            if (k%v[1] == 0 && k>0)
                ans = true;
        }
        int df3 = v[1]-v[0];
        k = v[1]+df3;
        if (k%v[2] == 0 && k>0)
            ans = true;
        if (ans) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";

    }
}