//34%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;

int main() {
    /*freopen("input.txt", "r", stdin);
    int n = 7647;
    string s[n];
    map<char,int> occ[200];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]+= ' ';
        for (int j = 0; j < (int) s[i].size(); j++) {
            occ[j][s[i][j]]++;
        }
    }
    int m[8][9];
    for (int i = 0; i < 8; i++) {
        set<pair<int,char>> st;
        for (auto [c,nb] : occ[i]) {
            st.insert({nb, c});
        }
        int nb = 0;
        for (auto it = st.rbegin(); it != st.rend(); it++) {
            cout << (*it).second;
            nb++;
            if (nb == 9)
                break;
        }
        cout << '\n';
    }*/

    string s = "scpabmtrd\n"
               "aeoirulhn\n"
               "ranteilso\n"
               "e itanlsr\n"
               " eistrnal\n"
               " ensritad\n"
               " esntrgda\n"
               " sedgynrt";
    cout << s;
}
