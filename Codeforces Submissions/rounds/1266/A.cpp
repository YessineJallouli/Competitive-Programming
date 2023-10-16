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
   while (T--) {
      string s; cin >> s;
      bool zero = false;
      bool odd = false;
      int somme = 0;
      for (int i = 0; i < s.size(); i++) {
         if ((s[i] - '0') % 2 == 0)
            if ((zero && s[i] == '0') || (s[i] != '0'))
               odd = true;
         if (s[i] == '0')
            zero = true;
         somme += s[i] - '0';
      }
      if (somme % 3 == 0 && zero && odd)
         cout << "red" <<'\n';
      else
         cout << "cyan" << '\n';
   }
}