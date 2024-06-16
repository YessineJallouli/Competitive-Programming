#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int d = n/m;
    if (d >= 150) {
        cout << "VERY HAPPY";
    }
    else if (d < 100) {
        cout << "SAD";
    }
    else {
        cout << "HAPPY";
    }
}
