#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, s;
        cin >> n >> s;
        int num[n];
        int nS[n+1];
        int all = 0;
        int maxi = 0;
        int id = 0;
        int idM = 0;
        bool b = false;
        for (int h = 0; h < n; h++)
            cin >> num[h];
        for (int h = 0; h < n; h++)
        {
            if (b && all+num[h] > s)
                break;
            if (num[h] > maxi)
            {
                maxi = num[h];
                id = h+1;
            }
            all += num[h];
            if (all > s)
            {
               all-= maxi;
               b = true;
               idM = id;
            }
        }
        cout << idM << endl;
    }
}