#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t;i++)
    {
        int a, b;
        cin >> a >> b;
        int k = abs(a-b);
        int somme = 0;
        int r = 1;
        int nb = 0;
        while (somme < k)
        {
            somme += r;
            r++;
            nb++;
        }
        if ((somme + k) % 2 == 0 )
            cout << nb << endl;
        else if ((somme + k + r) % 2 == 1)
            cout << nb+2 << endl;
        else
            cout << nb+1 << endl;
    }
}