#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int a,b,c;
        cin >> a >> b >> c;
        vector<int> v = {a,b,c};
        sort(v.begin(), v.end());
        cout << v[1] << '\n';
    }
}