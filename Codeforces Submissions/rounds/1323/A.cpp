/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--)
   {
      int n; cin >> n;
      int num[n+1];
      int id = -1, id1 = -1, id2 = -1;
      for (int i=1;i<=n;i++)
      {
         cin >> num[i];
         if (num[i] % 2 == 0)
            id = i;
         else if (id1 == -1)
            id1 = i;
         else
            id2 = i;
      }
      if (id != -1)
         cout << 1 << endl << id << endl;
      else if (id1 != -1 && id2 != -1)
         cout << 2 << endl << id1 << ' ' << id2 << endl;
      else
         cout << -1 << endl;
   }
}