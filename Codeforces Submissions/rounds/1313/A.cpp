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
      int num[3];
      for (int i = 0; i< 3; i++)
      {
         cin >> num[i];
         num[i] = min(num[i], 4);
      }
      sort(num, num+3);
      int a = num[0], b = num[1], c = num[2], nb = 0;
      if (a > 0) {a--; nb++;}
      if (b > 0) {b--; nb++;}
      if (c > 0) {c--; nb++;}
      if (a > 0 && c > 0) {a--; c--; nb++;}
      if (b > 0 && c > 0) {b--; c--; nb++;}
      if (a > 0 && b > 0) {a--; b--; nb++;}
      if (a > 0 && b > 0 && c > 0) {nb++;}
      cout << nb << endl;
   }
}