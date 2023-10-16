#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

string maxPalindromPrefix(string &s) {
   string s1 = s;
   reverse(s1.begin(), s1.end());
   s = s + '$' + s1;
   int n = s.size();
   int pr[n];
   pr[0] = 0;
   for (int i = 1; i < n; i++) {
      int j = pr[i-1];
      while (j && s[i] != s[j])
         j = pr[j-1];
      if (s[i] == s[j])
         j++;
      pr[i] = j;
   }
   return s.substr(0,pr[n-1]);
}

bool isPalindrome(string &s) {
   string s1 = s;
   reverse(s1.begin(), s1.end());
   return (s == s1);
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      if (isPalindrome(s)) {
         cout << s << '\n';
         continue;
      }
      int n = s.size();
      string ans = "";
      int i = 0, j = n-1;
      while (s[i] == s[j]) {
         ans+= s[i];
         i++; j--;
      }
      string ch = "";
      for (int id = i; id <= j; id++)
         ch+= s[id];
      s = ch;
      string s1 = s;
      reverse(s1.begin(), s1.end());
      string n1 = maxPalindromPrefix(s);
      string n2 = maxPalindromPrefix(s1);
      if (n2.size() > n1.size())
         swap(n1,n2);
      string ans1 = ans;
      reverse(ans1.begin(), ans1.end());
      ans+= n1;
      ans+= ans1;
      cout << ans << '\n';
   }
}