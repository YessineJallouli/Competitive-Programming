#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        if (x % 2 == 1)
            cout << "Bob\n";
        else {
            int y = x, cnt = 0;
            while (y % 2 == 0) {
                y /= 2;
                cnt += 1;
            }

            if (y != 1 || cnt % 2 == 0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
}