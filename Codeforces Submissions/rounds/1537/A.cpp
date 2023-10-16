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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      int sum = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         sum+= num[i];
      }
      if (sum < n) {
         cout << 1 << endl;
      }
      else {
         cout << sum-n << endl;
      }

   }
}