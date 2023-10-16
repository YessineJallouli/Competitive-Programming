#include <bits/stdc++.h>
using namespace std;

bool used1[9];
bool used2[9];

vector<pair<char,char>> v1;
vector<pair<char,char>> v2;

bool solve(int player, char lastC) {
    //cout << player << ' ' << lastC << '\n';
    if (player == 0) {
        bool ok = false;
        for (int i = 0; i < (int)v1.size(); i++) {
            if (! used1[i])
                ok = true;
        }
        if (! ok)
            return false;
        bool ans = false;
        map<pair<int,int>, char> usd;
        for (int i = 0; i < (int) v1.size(); i++) {
            if (used1[i])
                continue;
            auto [d,f] = v1[i];
            if (usd.count({d,f}))
                continue;
            usd[{d,f}] = true;
            if (d == lastC || lastC == '-') {
                used1[i] = true;
                ans |= solve(player^1, f);
                used1[i] = false;
            }
        }
        return ans;
    }
    else {
        bool ok = false;
        for (int i = 0; i < (int)v2.size(); i++) {
            if (! used2[i])
                ok = true;
        }
        if (! ok)
            return true;

        bool ans = false;
        map<pair<int,int>, char> usd;
        for (int i = 0; i < (int) v2.size(); i++) {
            if (used2[i])
                continue;
            auto [d,f] = v2[i];
            if (usd.count({d,f}))
                continue;
            usd[{d,f}] = true;
            if (d == lastC) {
                used2[i] = true;
                ans |= (!solve(player^1, f));
                used2[i] = false;
            }
        }
        return ! ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        v1.clear();
        v2.clear();
        memset(used1, false, sizeof used1);
        memset(used2, false, sizeof used2);
        int n1; cin >> n1;
        cin.ignore();
        for (int i = 0; i < n1; i++) {
            string s;
            getline(cin, s);
            char d = s[0], f = s.back();
            v1.emplace_back(d,f);
        }
        int n2; cin >> n2;
        cin.ignore();
        for (int i = 0; i < n2; i++) {
            string s;
            getline(cin, s);
            char d = s[0], f = s.back();
            v2.emplace_back(d,f);
        }
        string winner = "";
        if (solve(0,'-')) {
            winner = "player1";
        }
        else
            winner = "player2";
        cout << "Game " << t << ": " << winner << '\n';
    }
}