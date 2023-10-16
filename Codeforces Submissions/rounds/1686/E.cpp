#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string & s) {
    int n = 0;
    for (char c : s) {
        if (c == '(')
            n++;
        else
            n--;
        if (n < 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        n*= 2;
        string s; cin >> s;
        int pr[n+1];
        pr[0] = 0;
        for (int i = 1; i <= n; i++) {
            pr[i] = pr[i-1] + ((s[i-1] == '(') ? 1 : -1);
        }
//        for (int i = 0; i < n; i++) {
//            cout << pr[i] << ' ';
//        }
//        cout << '\n';
        if (isBalanced(s))
            cout << 0 << '\n';
        else {
            int idmn = 0;
            int idmx = 0;
            for (int i = 0; i < n; i++)
                if (pr[i] < 0)
                    idmx = i;
            for (int i = n-1; i >= 0; i--)
                if (pr[i] < 0)
                    idmn = i;
            int L = 0, R = idmx;
            //cout << idmx << ' ' << idmn << '\n';
            //cout << pr[L] << ' ' << pr[L] << '\n';
            for (int i = 0; i <= idmn; i++) {
                if (pr[L] < pr[i]) {
                    L = i;
                }
            }
            for (int i = idmx; i <= n; i++) {
                if (pr[R] < pr[i]) {
                    R = i;
                }
            }
            int id = 0;
            for (int i = 0; i <= n; i++) {
                if (pr[i] > pr[id])
                    id = i;
            }
            L++;
            reverse(s.begin()+L-1, s.begin()+R);
            if (isBalanced(s)) {
                cout << 1 << '\n' << L << ' ' << R << '\n';
            }
            else {
                cout << 2 << '\n';
                cout << 1 << ' ' << id << '\n';
                cout << id+1 << ' ' << n << '\n';
            }
        }
    }
}