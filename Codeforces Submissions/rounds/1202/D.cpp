#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int S = 2e4+7;
int cum[N];
bool dp[N][S];

void solve(int id = 0, int sum = 0) {
    if (id == N)
        return;
    if (dp[id][sum])
        return;
    dp[id][sum] = true;
    //cout << id << ' ' << sum << ' ' << nbChar << '\n';
    solve(id+1, sum+cum[id]);
    solve(id+1, sum);
}

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0);
    memset(dp, false, sizeof dp);
    for (int i = 0; i < N; i++) {
        cum[i] = i * (i - 1) / 2;
    }
    solve();
    int T; cin >> T;
    map<int,bool> forb;
    forb[2] = forb[5] = forb[8] = forb[12] = forb[23] = forb[33] = true;
    while (T--) {
        int n; cin >> n;
        if (forb[n]) {
            if (n%2 == 0) {
                cout << "1";
                n/= 2;
            }
            else {
                if (n == 5)
                    cout << "13713737\n";
                else if (n == 23)
                    cout << "13737371113737\n";
                else if (n == 33) {
                    cout << "137137371113737\n";
                }
                continue;
            }
        }
        int nb = 2;
        set<int> s;
        while (n > 1e4) {
            int cnt = 1;
            while (true) {
                if (cnt * (cnt + 1) / 2 + nb + 1 > n)
                    break;
                cnt++;
            }
            s.insert(cnt);
            n -= cnt * (cnt - 1) / 2;
        }
        int id = N-1;
        while (id != 1) {
            if (dp[id-1][n]) {
                id--;
            }
            else {
                n-= cum[id-1];
                id--;
                s.insert(id);
            }
        }
        cout << "1";
        for (int i = 0; i < *s.rbegin(); i++) {
            cout << "3";
            if (s.count(i+1))
                cout << "7";
        }
        cout << endl;

    }
}