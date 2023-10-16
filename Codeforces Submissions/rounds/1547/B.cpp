/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n =  s.size();
      bool b = true;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'a') {
            for (int j = i; j < n-1; j++) {
               if (s[j] > s[j+1])
                  b = false;
            }
            for (int j = 0; j < i; j++) {
               if (s[j] < s[j+1])
                  b = false;
            }
            break;
         }
      }
      sort(s.begin(), s.end());
      for (int i = 0; i < n; i++) {
         if (s[i] != i+'a')
            b = false;
      }
      if (b)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}