#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n+1];
    int id[n+1];
    int mx[n+1];
    int mn[n+1];
    for (int i = 1; i <= n; i++) {
       a[i] = i;
       id[i] = i;
       mn[i] = i;
       mx[i] = i;
    }
    for (int i = 0; i < m; i++) {
       int num; cin >> num;
       if (id[num] == 1)
          continue;
       int h = id[num]-1;
       int k = a[h];
       mn[num] = min(id[num]-1, mn[num]);
       mx[k] = max(mx[k], id[num]);
       id[num]--;
       id[k]++;
       swap(a[h], a[h+1]);
    }
    for (int i = 1; i <= n; i++) {
      cout << mn[i] << ' ' << mx[i] << endl;
    }
}