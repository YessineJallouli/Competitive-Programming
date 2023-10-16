#include<bits/stdc++.h>
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int a[n], b[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      for (int i= 0; i < n; i++)
         cin >> b[i];
      unordered_map<int, bool> One;
      unordered_map<int, bool> Neg;
      for (int i= 0; i < n-1; i++)
      {
         One[i+1] = One[i];
         Neg[i+1] = Neg[i];
         if (a[i] == 1)
            One[i+1] = true;
         if (a[i] == -1)
            Neg[i+1] = true;
      }
      bool answer = true;
      for (int i = n-1; i>=0; i--)
      {
         int D = b[i] - a[i];
         if (D > 0)
         {
            if (! One[i]) {
            cout << "NO" << endl;
            answer = false;
            break;
            }
         }
         else if (D < 0)
            if (! Neg[i]) {
               cout << "NO" << endl;
               answer = false;
               break;
         }
      }
      if (answer)
         cout << "YES" << endl;
      One.clear();
      Neg.clear();
   }
}