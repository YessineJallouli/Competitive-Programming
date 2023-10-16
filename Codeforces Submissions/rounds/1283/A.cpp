#include <bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int b = 24*60;
    for (int q = 0; q < t; q++)
    {
        int h, m; cin >> h >> m;
        cout << b-(h*60+m) << endl;
    }
}