#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      map<int,int> nb;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         nb[num[i]]++;
      }
      int mn = INT_MAX;
      for (int i = 0; i < n; i++) {
         mn = min(mn, nb[num[i]]);
      }
      int num_mn;
      int id;
      for (int i = 0; i < n; i++) {
         if (nb[num[i]] == mn) {
            num_mn = num[i];
            id = i+1;
            break;
         }
      }
      if (mn == n) {
         cout << "NO" << endl;
         continue;
      }
      //1 1 1 2 2 2

      cout << "YES" << endl;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         if (num[i] != num_mn) {
            cout << i+1 << ' ' << id << endl;
            v.push_back({i+1});
         }
      }
      for (int i = 0; i < n; i++) {
         if (num[i] == num_mn && i != id -1) {
            cout << i+1 << ' ' << v[v.size()-1]<< endl;
            v.pop_back();
         }
      }
   }
}