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
   SaveTime
   int n; cin >> n;
   while (n--)
   {
       int k; cin >> k;
       int nbM = 0;
       int nb = 0;
       bool b = false;
       char student[k];
       for (int i = 0; i < k; i++)
          cin >> student[i];
       for (int i = 0; i < k; i++)
       {
          if (student[i] == 'A') {
             nb = 0; b = true;}
          if (student[i] == 'P' && b)
             nb++;
          nbM = max(nb, nbM);
       }
       cout << nbM << endl;
   }
}