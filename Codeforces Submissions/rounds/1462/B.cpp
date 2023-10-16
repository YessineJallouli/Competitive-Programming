   #include <bits/stdc++.h>
   #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
   #define ll long long

   using namespace std;

   int main()
   {
      int T; cin >> T;
      while (T--) {
         bool b = false;
         int n; cin >> n;
         string s; cin >> s;
         string ch = "";
         for (int i = 0; i <= 4; i++) {
            ch = "";
            for (int k = 0; k < 4-i; k++) {
               ch+= s[k];
            }
            for (int j = n-i; j < n; j++) {
               ch+= s[j];
            }
            if (ch == "2020") {
               b = true;
            }
         }
         if (b) {
            cout << "YES" << endl;
         }
         else
            cout << "NO" << endl;
      }
   }