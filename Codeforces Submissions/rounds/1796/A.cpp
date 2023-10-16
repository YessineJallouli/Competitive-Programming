#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    string s = "";
    for (int i = 1; i <= 100; i++) {
        if (i%3 == 0)
            s+= 'F';
        if (i%5 == 0)
            s+= 'B';
    }
    while (T--) {
        int n; cin >> n;
        string t; cin >> t;
        bool ans = false;
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, n) == t) {
                ans = true;
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}