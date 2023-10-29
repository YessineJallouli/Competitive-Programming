/*
	Failure is not the reason for you to stop trying
	   it is actually a reminder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define pb push_back

using namespace std;


int main()
{
   int n; cin >> n;
   string s,s1;
   cin >> s >> s1;
   ll nb = 0;
   int nbO = 0;
   int nbOZ = 0;
   for (int i = 0; i < n; i++)
   {
      if (s[i] == '1')
         nbO++;
      if (s[i] == '1' && s1[i] == '0')
         nbOZ++;
   }
   for (int i = 0; i < n; i++)
   {
      if (s[i] == '0' && s1[i] == '0')
         nb+= nbO;
      else if (s[i] == '0' && s1[i] == '1')
         nb+= nbOZ;
   }

   cout << nb;


}
