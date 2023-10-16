#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PI 4*atan(1)
using namespace std;

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int k; cin >> k;
      string s; cin >> s;
      bool ans = true;
      for (int i = 0; i < n-k; i++) {
         if (s[i+k] == '?')
            s[i+k] = s[i];
         if (s[i] == '?')
            s[i] = s[i+k];
         if (s[i] != s[i+k])
            ans = false;
      }
      deque<int> quoi;
      int a = 0, b = 0;
      string ch = "";
      for (int i = 0; i < n; i++) {
         if (ch.size() == k) {
            if (ch[0] == '1')
               a--;
            if (ch[0] == '0')
               b--;
            if (ch[0] == '?')
               quoi.pop_front();
            ch.erase(ch.begin());
         }
         ch+= s[i];
         if (s[i] == '1')
            a++;
         if (s[i] == '0')
            b++;
         if (s[i] == '?')
            quoi.push_back(i);
         if (a == k/2) {
            for (int i : quoi) {
               s[i] = '0';
            }
            break;
         }
         if (b == k/2) {
            for (int i : quoi)
               s[i] = '1';
            break;
         }
      }
      for (int i = 0; i < n-k; i++) {
         if (s[i+k] == '?')
            s[i+k] = s[i];
         if (s[i] == '?')
            s[i] = s[i+k];
         if (s[i] != s[i+k])
            ans = false;
      }
      a = 0; b = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '0')
            a++;
         if (s[i] == '1')
            b++;
      }
      a = 0, b = 0;
      ch = "";
      for (int i = 0; i < n; i++) {
         if (ch.size() == k) {
            if (ch[0] == '1')
               a--;
            if (ch[0] == '0')
               b--;
            ch.erase(ch.begin());
         }
         ch+= s[i];
         if (s[i] == '1')
            a++;
         if (s[i] == '0')
            b++;
         if (a > k/2 || b > k/2)
            ans = false;
      }
      for (int i = 0; i < n-k; i++) {
         if (s[i+k] == '?')
            s[i+k] = s[i];
         if (s[i] == '?')
            s[i] = s[i+k];
         if (s[i] != s[i+k])
            ans = false;
      }
      if (a > (n+1)/2 || b > (n+1)/2)
         ans = false;
      if (ans)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}