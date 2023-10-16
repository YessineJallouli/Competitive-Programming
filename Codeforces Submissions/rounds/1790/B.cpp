#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        int n,s,r; cin >> n >> s >> r;
        int mx = s-r;
        cout << mx << ' ';
        n--;
        int moy = r/n;
        for (int i = 0; i < r%n; i++) {
            cout << moy+1 << ' ';
        }
        for (int i = 0; i < n-r%n; i++) {
            cout << moy << ' ';
        }
        cout << '\n';
    }
}