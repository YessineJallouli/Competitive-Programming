/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define pb push_back

using namespace std;


int main()
{
   int t; cin >> t;
   while (t--)
   {
      unsigned long long int a, b,c; cin >> a >> b >> c;
      double f = (double) a/2; unsigned long long half = ceil(f);
      if (b >= half || b >= c)
         cout << a << endl;
      else
      {
         unsigned long long int S = half / b;
         unsigned long long int modu = half % b;
         if (modu == 0)
            S--;
         unsigned long long int  nb = S * (b+c);
         unsigned long long int fmdl = nb+modu;
         if (modu == 0)
            fmdl+= b;
         if (fmdl < a)
            cout << a << endl;
         else
            cout << fmdl << endl;
      }
   }
}