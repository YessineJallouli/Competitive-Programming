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
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      sort(num, num+n);
      if (num[0] == num[n-1]) {
         for (int i = 0; i < n; i++)
            cout << num[i] << ' ';
         cout << endl;
         continue;
      }
      int diffmin = INT_MAX;
      for (int i = 1; i < n; i++) {
         if (diffmin >= num[i]-num[i-1]) {
            diffmin = num[i]-num[i-1];
         }
      }
      int id;
      for (int i = 1; i < n; i++) {
         if (num[i]-num[i-1] == diffmin) {
            id = i-1;
            break;
         }
      }
      cout << num[id] << ' ';
      for (int i = id+2; i < n; i++)
         cout << num[i] << ' ';
      for (int i = 0; i < id; i++) {
         cout << num[i] << ' ';
      }
      cout << num[id+1] << endl;
   }
}