#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a, a+m);
        int diff[m];
        int nbS = 0;
        for (int i = 0; i < m; i++) {
            if (i == m-1) {
                diff[i] = n-a[i]+a[0]-1;
            }
            else {
                diff[i] = a[i + 1] - a[i]-1;
            }
        }
        sort(diff, diff+m);
        int nbJ = 0;
        for (int i = m-1; i >= 0; i--) {
            if (diff[i]-nbJ*2 == 1) {
                nbS+= 1;
                break;
            }
            nbS+= max(0, diff[i]-1-nbJ*2);
            nbJ+= 2;
        }
        cout << n-nbS << '\n';
    }

}