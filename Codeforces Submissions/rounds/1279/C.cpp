#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int h = 0; h < t; h++)
    {
         int n, m; cin >> n >> m;
         int a[n], b[m];
         bool visited[n+1] = {false};
         int id[n+1];
         for (int l = 0; l < n; l++)
         {
             cin >> a[l];
             id[a[l]] = l;
         }

         for (int l = 0; l < m; l++)
         {
             cin >> b[l];
             visited[b[l]] = true;
         }
         int idM = 0;
         unsigned long long int s = 0;
         for (int l = 0; l <m; l++)
         {
             int num = b[l];
             if (id[num] <= idM)
                s = s+ 1;
             else
                s = s+ (id[num]-l)*2 + 1;
             idM = max(id[num], idM);
         }
         cout << s << endl;
    }

}