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
   int n, a, b,k;
   cin >> n >> a >> b >> k;
   int num[n];
   for (int i = 0; i < n; i++)
   {
      int k; cin >> k;
      num[i] = k%(a+b);
      if (num[i] == 0)
         num[i] = a+b;
   }
   sort(num, num+n);
   /*for (int i= 0; i < n; i++)
      cout << num[i] << ' ';
   cout << endl;*/
   int nb = 0;
   for (int i = 0; i < n; i++)
   {
      if (a >= num[i])
         nb++;
      else
      {
         int hi = (num[i] / a) - (num[i] % a == 0);
         if (k >= hi)
         {
            k = k-hi;
            nb++;
         }
      }
   }
   cout << nb;
}