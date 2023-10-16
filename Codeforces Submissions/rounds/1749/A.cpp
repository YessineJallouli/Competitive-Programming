#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int col[8];
        int row[8];
        for (int i = 0; i < 8; i++) {
            col[i] = row[i] = 0;
        }
        bool ans = true;
        if (m >= n) {
            ans = false;
        }
        for (int i = 0; i < m; i++) {
            int x,y; cin >> x >> y;
            x--; y--;
            col[x]++;
            row[y]++;
        }
        int nb1 = 0;
        int nb2 = 0;
        for (int i = 0; i < 8; i++) {
            if (col[i] == 2)
                nb1++;
            if (row[i] == 2)
                nb2++;
            if (col[i] > 2 || row[i] > 2)
                ans = false;
        }
        if (nb1 > 1 || nb2 > 1)
            ans = false;
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}