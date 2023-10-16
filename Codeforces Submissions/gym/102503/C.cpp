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
   for (int i = 0; i < t; i++)
   {
      int n; cin >> n;
      string s; cin >> s;
      int a, b, c; a = b= c = 0;
      for (int k = 0; k < n-1; k++)
      {
         string h = "";
         h +=s[k];
         h +=s[k+1];
         string h1 = h;
         if (k < n-2)
            h1 +=s[k+2];
         if (h == "TJ")
            a++;
         if (h == "si")
            b++;
         if (h1 == "log")
            c++;
      }
      cout << a << ' ' << b << ' ' << c << '\n';
   }
}