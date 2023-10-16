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

char c(char c1, char c2)
{
   if (c1 > c2)
      swap(c1,c2);
   if (c1 == 'E' && c2 == 'S')
      return 'T';
   if (c1 == 'E' && c2 == 'T')
      return 'S';
   return 'E';

}

int main()
{
   SaveTime
   int n, k; cin >> n >> k;
   cin.ignore();
   map<string, bool> mapa;
   string card[n];
   for (int i = 0; i < n; i++)  {
       getline(cin, card[i]); mapa[card[i]] = true;
   }
   if (n < 3)
   {
      cout << 0;
      return 0;
   }
   int nb = 0;
   for (int i = 0; i < n; i++)
   {
      for (int t = i+1; t < n; t++)
      {
          string abc = "";
          for (int h = 0; h < k; h++)
          {
              if (card[t][h] == card[i][h])
                abc += card[t][h];
              else
                abc += c(card[t][h], card[i][h]);
          }
          if (mapa[abc])
             nb++;
      }
   }
   cout << (int) nb/3;

}