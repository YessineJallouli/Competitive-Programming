//100%
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x%= 180;
            if (x < 0)
                x+= 180;
            s.insert(x);
        }
        cout << max(1,(int) s.size()*2) << '\n';
    }
}
