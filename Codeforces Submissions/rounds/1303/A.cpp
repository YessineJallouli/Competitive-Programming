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
      string s; cin >> s;
      int nb = 0;
      bool b = false;
      int nbM = 0;
      for (int i = 0; i < s.size(); i++)
      {
         if (s[i] == '1' && !b)
            b = true;
         if (s[i] == '1' && b)
         {
            nbM += nb;
            nb = 0;
         }
         if (b && s[i] == '0')
            nb++;
      }
      cout << nbM << endl;

   }
}