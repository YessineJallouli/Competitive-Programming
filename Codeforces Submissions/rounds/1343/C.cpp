#include<bits/stdc++.h>
#define MOD 1e9+7
#define ll long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      ll num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      bool negative = true;
      int k = 0;
      for (int i = 0; i < n; i++) {
         if (num[i] < 0 && negative) {
            k++;
            negative = false;
            continue;
         }
         else if (num[i] > 0 && ! negative) {
            k++;
            negative = true;
            continue;
         }
      }
      int k1 = 0;
      negative = false;
      for (int i = 0; i < n; i++) {
         if (num[i] > 0 && ! negative) {
            k1++;
            negative = true;
            continue;
         }
         else if (num[i] < 0 && negative) {
            k1++;
            negative = false;
            continue;
         }
      }
      ll sum = 0; ll sum1 = 0;
      //cout << k << ' ' << k1 << endl;
      if (k >= k1) {
         bool neg = true;
         ll maxi = 0, mini = -1000000001;
         for (int i = 0; i < n; i++) {
            if (num[i] < 0 && neg) {
               mini = max({num[i], mini});
               maxi = 0;
               if (i != n-1) {
                  if (num[i+1] > 0) {
                     sum+= mini;
                     neg = false;
                  }
               }
               else
                  sum+= mini;
            }
            else if (num[i] > 0 && !neg) {
               maxi = max({num[i], maxi});
               mini = -1000000001;
               if (i != n-1) {
                  if (num[i+1] < 0) {
                     sum+= maxi;
                     neg = true;
                  }
               }
               else
                  sum+= maxi;
            }
         }
      }
      else if (k <= k1) {
         bool neg = false;
         ll maxi = 0, mini = -1000000001;
         for (int i = 0; i < n; i++) {
            //cout << sum1 << endl;
            if (num[i] < 0 && neg) {
               mini = max({num[i], mini});
               maxi = 0;
               if (i != n-1) {
                  if (num[i+1] > 0) {
                     sum1+= mini;
                     neg = false;
                  }

               }
               else
                  sum1+= mini;
               continue;
            }
            else if (num[i] > 0 && !neg) {
               maxi = max({num[i], maxi});
               mini = -1000000001;
               if (i != n-1) {
                  if (num[i+1] < 0) {
                     sum1+= maxi;
                     neg = true;
                  }
               }
               else
                  sum1+= maxi;
               continue;
            }
         }
      }
      if (k < k1)
         cout << sum1 << endl;
      else if (k > k1)
         cout << sum << endl;
      else
         cout << max(sum, sum1) << endl;
   }
}