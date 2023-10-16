//
// Created by yessine on 12/16/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool can(int m) {
    return m%2;
}

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[n-1]) {
        if (s[0] == '1')
            cout << (1<<n);
        else
            cout << 1;
        return 0;
    }
    int lw = 1;
    int p2 = 1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            if (i == n-1)
                break;
            lw = p2;
            break;
        }
        p2*= 2;
    }
    reverse(s.begin(), s.end());
    int up = 1;
    p2 = 1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            if (i == n-1)
                break;
            up = (1<<n)-p2+1;
            break;
        }
        p2*= 2;
    }
    for (int i = lw; i <= up; i++)
        cout << i << ' ';
}