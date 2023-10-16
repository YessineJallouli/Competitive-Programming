/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
   int n, k; cin >> n >> k;
   string ans = "";
   for (int i = 0; i < k; i++)
      ans+= 'z';
   string s; cin >> s;
   for (int i = 0; i < n; i++) {
      string ch = s.substr(0,i+1);
      while (ch.size() < k) {
         ch = ch+ch;
      }
      //cout << ch.size() << endl;
      while (ch.size() > k) {
         ch.erase(ch.size()-1);
      }
      if (ch < ans)
         ans = ch;
   }
   cout << ans;
}