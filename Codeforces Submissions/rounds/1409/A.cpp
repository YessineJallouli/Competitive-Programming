#include<bits/stdc++.h>
using namespace std;

int main()
{
   int T; cin >> T;
   for (int i = 0; i < T; i++) {
   int a, b; cin >> a >> b;
   if (a > b) swap(a, b);
   int ans = (b-a)/10;
   if ((b-a)%10 != 0)
      ans++;
   cout << ans << endl;
   }
}