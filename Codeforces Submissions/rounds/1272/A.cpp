#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    for (int h = 0; h < q; h++)
    {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        if (a[2] == a[1] && a[1] != a[0])
        {
            a[2]--;
            a[1]--;
        }
        else if (a[1] == a[0] && a[1]!= a[2])
        {
            a[0]++; a[1]++;
        }
        if (a[0] < a[1])
            a[0]++;
        if (a[2] > a[1])
            a[2]--;
        cout << 2*(a[2] - a[0]) << endl;
    }
}