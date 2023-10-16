#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int mx[10];
        memset(mx, -1, sizeof mx);
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            mx[b-1] = max(mx[b-1], a);
        }
        int s = 0;
        bool r = false;
        for (int i = 0; i < 10; i++) {
            s+= mx[i];
            if (mx[i] == -1)
                r = true;
        }
        if (r) {
            cout << "MOREPROBLEMS" << '\n';
        }
        else {
            cout << s << '\n';
        }

    }
}