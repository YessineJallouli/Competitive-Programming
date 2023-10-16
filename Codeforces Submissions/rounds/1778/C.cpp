#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long solve(const string &a, const string &b) {
    long long res = 0;
    long long nb = 0;
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            res+= nb*(nb+1)/2;
            nb = 0;
        }
        else {
            nb++;
        }
    }
    res+= nb*(nb+1)/2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        set<char> cr;
        string a,b; cin >> a >> b;
        if (k == 10) {
            cout << 1LL*n*(n+1)/2 << '\n';
            continue;
        }
        for (char c : a)
            cr.insert(c);

        vector<char> car;
        for (char c : cr)
            car.push_back(c);

        k = min(k, (int) car.size());
        if (k == car.size()) {
            cout << 1LL*n*(n+1)/2 << '\n';
            continue;
        }
        int sz = (int) car.size();
        long long ans = 0;
        for (int i = 0; i < (1 << sz); i++) {
            int nb = 0;
            set<char> st;
            for (int j = 0; j < sz; j++) {
                if (i & (1 << j)) {
                    nb++;
                    st.insert(car[j]);
                }
            }
            if (nb == k) {
                string ch = "";
                for (int j = 0; j < n; j++) {
                    char c = a[j];
                    if (st.count(c)) {
                        ch+= b[j];
                    }
                    else {
                        ch+= a[j];
                    }
                }
                //cout << ch << '\n';
                ans = max(ans, solve(ch, b));
            }
        }
        cout << ans << '\n';
    }
}