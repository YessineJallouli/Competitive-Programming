#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
       ll n,x,y; cin >> n >> x >> y;
       ll diff = (x-y)%2;
       if (diff < 0)
           diff+= 2;
       int a[n];
       ll sum = 0;
       for (int i = 0; i < n; i++) {
           cin >> a[i];
           sum+= a[i];
       }
       if (sum%2 == diff) {
            cout << "Alice\n";
       }
       else
           cout << "Bob\n";
   }
}