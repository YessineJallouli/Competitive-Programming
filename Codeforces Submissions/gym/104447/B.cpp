#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tmm(string &s) {
    int res = 0;
    res+= (s[0]-'0')*10;
    res+= (s[1]-'0');
    res*= 60;
    res+= (s[3]-'0')*10;
    res+= (s[4]-'0');
    return res;
}

string h(int n) {
    if (n >= 1440)
        return "23:59";
    int k = n/60;
    string s = to_string(k);
    if (s.size() == 1)
        s = '0' + s;
    int h = n%60;
    if (h < 10)
        s = s + ":0" + to_string(h);
    else
        s = s + ":" + to_string(h);
    return s;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k,m; cin >> n >> k >> m;
        int hhh; cin >> hhh;
        string s; cin >> s;
        int minutes = tmm(s) + k;
        int ans = 0;
        for (int i = 0; i < m-1; i++) {
            int id; cin >> id;
            cin >> s;
            string last = h(minutes);
            if (s <= last) {
                minutes = tmm(s) + k;
            }
            else {
                ans++;
                minutes = tmm(s) + k;
            }
        }
        cout << ans+1 << '\n';
    }

}