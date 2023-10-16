/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool possible(int a, int b) {
   int diff = 0;
   for (int i = 1; i <= max(a,b); i*= 2) {
      int bit1 = ((a&i) > 0);
      int bit2 = ((b&i) > 0);
      diff+= bit1-bit2;
      if (diff < 0)
         return false;
   }
   return true;
}

void solve() {
   int a,b; cin >> a >> b;
   if (a > b) {
      cout << "NO" << endl;
      return;
   }
   if (possible(a,b)) {
      cout << "YES" << endl;
   }
   else
      cout << "NO" << endl;
}

int main()
{
   int T; cin >> T;
   while (T--) {
      int n,x; cin >> n >> x;
      ll a1 = 0, a2;
      ll sum = 0;
      for (int i = 0; i < n; i++) {
         int num; cin >> num;
         sum+= num;
         a1+= (num+(x-1))/x;
      }
      a2 = (sum+(x-1))/x;
      cout << a2 << ' ' << a1 << endl;
   }
}