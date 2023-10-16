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
      int n; cin >> n;
      set<int> s;
      for (int i = 0; i < n; i++)
      {
         int num; cin >> num;
         s.insert(num);
      }
      cout << s.size() << endl;
      s.clear();
   }
}