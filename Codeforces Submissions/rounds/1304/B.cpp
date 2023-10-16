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

int n, m;

bool isPalindrome(string S)
{
   for (int i = 0; i < m/2;i++)
      if (S[i] != S[m-1-i])
         return false;
   return true;
}
string invert(string S)
{
   string T = "";
   for (int i = 0; i < m; i++)
      T = S[i] + T;
   return T;
}

int main()
{
   cin >> n >> m ;
   string mot[n]; map<string, bool> mapa;
   vector<string> P;
   vector<string> nP;
   for (int i = 0; i < n; i++)
   {
      cin >> mot[i];
      mapa[mot[i]] = true;
      if (isPalindrome(mot[i]))
         P.push_back(mot[i]);
      if (invert(mot[i]) != mot[i] && mapa[invert(mot[i])])
         nP.push_back(mot[i]);
   }
   string s = "";
   for (string t : nP)
      s = t + s + invert(t);
   int h = s.size();
   if (P.size() != 0)
   {
      string p = "";
      string PP = P[0];
      for (int t = 0; t < h/2; t++)
         p += s[t];
      for (int t = 0; t < PP.size(); t++)
         p += PP[t];
      for (int t = h/2; t < h; t++)
         p += s[t];
      s = p;
   }
   cout << s.size() << endl;
   cout << s;

}