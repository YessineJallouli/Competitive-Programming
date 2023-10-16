#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int mxPos[N];

int main() {
    int T; cin >> T;
    while (T--) {
        memset(mxPos, -1, sizeof mxPos);
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mxPos[x] = i+1;
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i++) {
            if (mxPos[i] == -1)
                continue;
            for (int j = i; j <= 1000; j++) {
                if (mxPos[j] == -1)
                    continue;
                if (__gcd(i,j) == 1) {
                    ans = max(ans, mxPos[i]+mxPos[j]);
                }
            }
        }
        cout << ans << '\n';
    }
}