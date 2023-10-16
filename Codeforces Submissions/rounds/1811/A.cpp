//
// Created by yessine on 4/4/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,d; cin >> n >> d;
        string s; cin >> s;
        bool b = false;
        for (int i = 0; i < n; i++) {
            if (s[i]-'0' < d) {
                for (int j = 0; j < i; j++)
                    cout << s[j];
                cout << d;
                for (int j = i; j < n; j++)
                    cout << s[j];
                b = true;
                break;
            }
        }
        if (! b)
            cout << s << d;
        cout << '\n';
    }
}