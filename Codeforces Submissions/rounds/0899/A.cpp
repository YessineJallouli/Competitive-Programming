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
   int n; cin >> n; int num[n];
   int nbO = 0; int nbT = 0;
   for (int i= 0; i < n; i++)
   {
      cin >> num[i];
      if (num[i] == 1) nbO++; else nbT++;
   }
   int nb = min({nbO, nbT});
   int K = nbO- nb;
   if (K > 0) nb+= K/3;
   cout << nb;

}