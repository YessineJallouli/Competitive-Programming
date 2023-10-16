#include <bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, k; cin >> n >> k;
        if (n % k == 0)
            cout << n << endl;
        else
        {
            int m = n/k;
            int h = k/2;
            if (h*(m+1) + (k-h)*m > n)
                cout << n << endl;
            else
                cout << h*(m+1) + (k-h)*m  << endl;
        }
    }
}