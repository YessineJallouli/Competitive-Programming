/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   vector<string> v; map<string, bool> m;
   for (char c = 'z'; c >= 'a'; c--) {
      string ch = "";
      ch+= c;
      v.push_back(ch);
      for (char c1 = 'a'; c1 <= 'z'; c1++) {
         string ch1 = ch+c1;
         v.push_back(ch1);
         for (char c2 = 'a'; c2 <= 'z'; c2++) {
            string ch2 = ch1 + c2;
            v.push_back(ch2);
         }
      }
   }
   sort(v.begin(), v.end(),[&] (string &s1, string &s2)
   {
      if(s1.size() != s2.size())
         return s1.size() < s2.size();
      return s1 < s2 ;
   });
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      for (int l1 = 1; l1 <= 3; l1++) {
         for (int i = 0; i < n; i++) {
            if (l1+i <= n) {
               string ch = s.substr(i,l1);
               m[ch] = true;
            }
         }
      }
      for (string s : v) {
         if (! m[s]) {
            cout << s << endl;
            break;
         }
      }
      m.clear();
   }
}