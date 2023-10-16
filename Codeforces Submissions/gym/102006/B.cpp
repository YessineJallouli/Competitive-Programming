#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    freopen("hamming.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string a,b; cin >> a >> b;
        int nb1 = 0, nb2 = 0;
        for (char c : a) {
            nb1+= c-'0';
        }
        for (char c : b)
            nb2+= c-'0';
        cout << min(nb1, n-nb2) + min(nb2, n-nb1) << '\n';
    }
}