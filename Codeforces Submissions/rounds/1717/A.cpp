#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        cout << n+2*(n/3)+2*(n/2) << '\n';
    }
}