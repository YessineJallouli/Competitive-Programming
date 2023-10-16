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
#define PI 4*atan(1)

using namespace std;

const int M = (int)(2e6 + 239);

int pref[M], c;

string Pald(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

int main()
{
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      bool b = true;
      for (int i = 0; i < (s.size() / 2) && b; i++) {
         if (s[i] != s[s.size()-i-1]) {
            b = false;
            string f = s.substr(i, s.size()-2*i);
            string prefix = Pald(f);
            reverse(f.begin(), f.end());
            string suffix = Pald(f);
            string maxi = prefix;
            if (prefix.size() < suffix.size())
               maxi = suffix;
            f = s.substr(0, i);
            prefix = f;
            reverse(prefix.begin(), prefix.end());
            string s1 = "" + f + "" + maxi + "" + prefix;
            string s2 = Pald(s);
            reverse(s.begin(), s.end());
            string s3 = Pald(s);
            string perfect = s1;
            if (s1.size() < s2.size())
               perfect = s2;
            if (perfect.size() < s3.size())
               perfect = s3;
            cout << perfect << '\n';
         }
      }
      if (b)
         cout << s << '\n';
   }
}