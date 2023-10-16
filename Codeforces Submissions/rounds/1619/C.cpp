#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        ll a,b; cin >> a >> b;
        if (a > b) {
            cout << -1 << '\n';
            continue;
        }
        string x = to_string(a);
        string y = to_string(b);
        string res = "";
        int i = x.size()-1;
        int j = y.size()-1;
        bool ans = true;
        while (i >= 0 && j >= 0 && ans) {
            int c = x[i]-'0';
            int d = y[j]-'0';
            if (c <= d)
                res = res + char(d-c+'0');
            else {
                if (j == 0)
                    ans = false;
                j--;
                if (y[j] == '1')
                    res = res + char(d-c+10+'0');
                else
                    ans = false;
            }
            j--;
            i--;
        }
        if (i == -1 && ans) {
            reverse(res.begin(), res.end());
            for (int i = 0; i <= j; i++)
                cout << y[i];
            int id = 0;
            while (id != res.size() && res[id] == '0' && j == -1)
                id++;
            for (int i = id; i < res.size(); i++)
                cout << res[i];
            if (id == res.size())
                cout << 0;
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}