#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> ask(int i ,int j) {
    cout << "? " << i << ' ' << j << endl;
    int n = j-i+1;
    vector<int> v;
    for (int l = 0; l < n; l++) {
        int x; cin >> x;
        v.push_back(x);
    }
    return v;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int d = 1, f = n;
        int ans = -1;
        while (d <= f) {
            int m = (d+f)/2;
            vector<int> q = ask(d,m);
            int rightPlace = 0;
            for (int i : q) {
                if (i >= d && i <= m)
                    rightPlace++;
            }
            if (rightPlace%2 == 0) {
                d = m+1;
            }
            else {
                f = m-1;
                ans = m;
            }
        }
        cout << "! " << ans << endl;
    }
}