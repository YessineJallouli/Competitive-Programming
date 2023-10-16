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
   int n; cin >> n;
   int num[n], num1[n];
   int s = 0, s1 = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> num[i];
      s+= num[i];
   }
   int nb = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> num1[i];
      s1+= num1[i];
      if (num[i] && !num1[i])
         nb++;
   }
   if (s1 < s)
      cout << 1;
   else if (s1 == s && nb)
      cout << 2;
   else if (s1 > s && nb)
   {
      int h = s1 - s+1;
      int k = ceil((double)h/nb) +1;
      cout << k;
   }
   else
      cout << -1;

}