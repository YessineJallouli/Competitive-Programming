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
   int N; cin >> N;
   for (int i = 0; i < N; i++)
   {
      int nb; cin >> nb;
      int num[nb];
      int s = 0;
      string Ch;
      cin >> Ch;
      for (int t= 0; t < nb; t++)
      {
         num[t] = Ch[t] - '0';
         s+= num[t];
      }
      int num1 = -1, num2 = -1;
      int id = -1;
      for (int t = 0; t < nb; t++)
         if (num[t] % 2 == 1)
         {
            id = t;
            num1 = num[t];
            break;
         }
      for (int t = id+1; t < nb; t++)
         if (num[t] % 2 == 1)
         {
            num2 = num[t];
            break;
         }
      if (num1 != -1 && num2 != -1)
         cout << num1 << num2 << endl;
      else
         cout << -1 << endl;
   }
}