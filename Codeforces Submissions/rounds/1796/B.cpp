#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string a,b; cin >> a >> b;
        if (a[0] == b[0]) {
            cout << "YES\n";
            cout << a[0] << '*' << '\n';
        }
        else if (a.back() == b.back()) {
            cout << "YES\n";
            cout << '*' << a.back() << '\n';
        }
        else {
            bool ans = false;
            map<string, bool> m;
            for (int i = 0; i < (int) a.size()-1; i++) {
                m[a.substr(i,2)] = true;
            }
            for (int i = 0; i < (int) b.size()-1; i++) {
                if (m[b.substr(i,2)]) {
                    ans = true;
                    cout << "YES\n";
                    cout << '*' << b.substr(i,2) << '*' << '\n';
                    break;
                }
            }
            if (! ans) {
                cout << "NO\n";
            }
        }
    }
}