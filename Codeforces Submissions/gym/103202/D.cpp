/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

set<string> s;

ll N;

void brute(int n,string ch) {
   if (n == 0) {
      s.insert(ch);
      return ;
   }
   brute(n-1, ch+'r');
   brute(n-1, ch+'b');
}
void brute2(int nb1, int nb2, string ch) {
   if (nb1 == 0 && nb2 == 0) {
      s.insert(ch);
      return;
   }
   if (nb1 != 0)
      brute2(nb1-1, nb2, ch+'r');
   if (nb2 != 0)
      brute2(nb1, nb2-1, ch+'b');
}

int nb(string s) {
   int ans = 0;
   int n = s.size();
   for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = i; j < n; j++) {
         if (s[j] == 'r')
            cnt++;
         if (cnt%2)
            ans++;
      }
   }
   return ans;
}

int main() {
   SaveTime
   cin >> N;
   if (N%2 == 1) {
      cout << (N+1)/2 * (N+1)/2 << '\n';
   }
   else {
      cout << N*(N+1)/2 - (N/2)*(N/2) << '\n';
   }
   if (N <= 21) {
      vector<char> v;
      brute(N, "");
      string ch = "";
      for (string s1 : s)
         ch = s1;
      int ans = 0;
      for (string s1 : s) {
         if (nb(s1) == nb(ch)) {
            ans++;
            cout << s1 << endl;
            if (ans == 100)
               break;
         }
      }
   }
   else if (N <= 62) {
      vector<char> v;
      int rem = N/2-6;
      int k = N-rem;
      string off = "";
      for (int i = 0; i < rem; i++)
         off+= 'b';
      for (int i = 1; i <= 5; i++) {
         brute2(i, k-i, off);
      }
      string ch = "";
      for (int i = 0; i < N; i++)
         ch+= 'r';
      int ans = 0;
      int HH = nb(ch);
      for (string s1 : s) {
         if (HH == nb(s1)) {
            ans++;
            cout << s1 << endl;
            if (ans == 100)
               break;
         }
      }
   }
   else if (N <= 195) {
      string mrgl = "";
      for (int i = 0; i < N/2; i++)
         mrgl+= 'b';
      mrgl+= 'r';
      int rem = N-mrgl.size();
      for (int i = 0; i < rem; i++)
         mrgl+= 'b';
      s.insert(mrgl);

      mrgl = "";
      for (int i = 0; i < (N-2)/2; i++)
         mrgl+= 'b';
      mrgl+= 'r';
      rem = N-mrgl.size();
      for (int i = 0; i < rem; i++)
         mrgl+= 'b';
      s.insert(mrgl);
      mrgl.back() = 'r';
      s.insert(mrgl);
      mrgl[mrgl.size()-2] = 'r';
      s.insert(mrgl);
      for (int i = N-1; i > N/2; i--) {
         swap(mrgl[i], mrgl[i-2]);
         s.insert(mrgl);
      }
      string ch = "";
      for (int i = 0; i < (N-4)/2; i++)
         ch+= 'b';
      ch+= 'r';
      for (int i = 0; i < N/3-1; i++)
         ch+= 'b';
      int k = N-ch.size();
      for (int i = 1; i <= 5; i++) {
         brute2(i, k-i, ch);
      }
      string ch1 = "";
      for (int i = 0; i < N; i++)
         ch1+= 'r';
      int ans = 0;
      int HH = nb(ch1);
      for (string s1 : s) {
         if (HH == nb(s1)) {
            ans++;
            cout << s1 << endl;
            if (ans == 100)
               break;
         }
      }
      //cout << ans << '\n';
   }
   else {
      int FF = 0;
      string mrgl = "";
      for (int i = 0; i < N/2; i++)
         mrgl+= 'b';
      mrgl+= 'r';
      int rem = N-mrgl.size();
      for (int i = 0; i < rem; i++)
         mrgl+= 'b';
      s.insert(mrgl);
      mrgl = "";
      for (int i = 0; i < (N-2)/2; i++)
         mrgl+= 'b';
      mrgl+= 'r';
      rem = N-mrgl.size();
      for (int i = 0; i < rem; i++)
         mrgl+= 'b';
      if (N%2 == 0)
         s.insert(mrgl);
      mrgl.back() = 'r';
      s.insert(mrgl);
      mrgl[mrgl.size()-2] = 'r';
      s.insert(mrgl);
      for (int i = N-1; i > N/2; i--) {
         FF++;
         swap(mrgl[i], mrgl[i-2]);
         s.insert(mrgl);
         if (FF > 400)
            break;
      }
      string ch1 = "";
      for (int i = 0; i < N; i++)
         ch1+= 'r';
      int ans = 0;
      int HH = nb(ch1);
      for (string s1 : s) {
         ans++;
         cout << s1 << endl;
            if (ans == 100)
               break;
      }
      //cout << ans;
   }
}