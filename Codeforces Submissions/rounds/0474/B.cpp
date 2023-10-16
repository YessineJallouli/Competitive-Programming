#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int binarysearch(int x, int num[], int &n) {
   int beg = 0, ennd = n-1;
   /// 2 9 12 16 25
   /// 1 25 11
   int med;
   while (beg < ennd) {
      //cout << beg << ' ' << ennd << endl;
      med = (ennd+beg)/2;
      if (num[med] < x)
         beg = med+1;
      else if (num[med] > x) {
         ennd = med;
      }
      else
         return med+1;
   }
   return beg+1;
}

int main()
{
   int n; cin >> n;
   int num[n];
   cin >> num[0];
   for (int i = 1; i < n; i++) {
      int x; cin >> x;
      num[i] = num[i-1]+x;
   }
   int k; cin >> k;
   for (int i = 0; i < k; i++) {
      int x; cin >> x;
      cout << binarysearch(x, num, n) << endl;
   }
}