#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int h = 0; h < t; h++)
    {
         int r,b,g;
         cin >> r >> b >> g;
         if (r+b+1 >= g && r+g+1 >= b && b+g+1 >= r)
            cout << "YES" << endl;
         else
            cout << "NO" << endl;
    }

}