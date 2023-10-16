/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 3e6;
int greater_div[mx];
int rk[mx];

int main()
{
   SaveTime
   memset(greater_div, -1, sizeof greater_div);
   for (int i = 2; i < mx; i++) {
      if (greater_div[i] == -1) {
         for (int j = i; j < mx; j+= i) {
            if (greater_div[j] == -1)
               greater_div[j] = i;
         }
      }
   }
   int nb1 = 1;
   for (int i = 2; i < mx; i++) {
      if (greater_div[i] == i) {
         rk[i] = nb1;
         nb1++;
      }
      greater_div[i] = i/greater_div[i];
   }

   int n; cin >> n;
   n*=2;
   int num[n];
   map<int,int> nb;
   for (int i = 0; i < n; i++) {
      cin >> num[i];
      nb[num[i]]++;
   }
   sort(num, num+n, greater<int>());
   vector<int> ans;
   for (int i = 0; i < n; i++) {
      int x = num[i];
      if (nb[x] == 0)
         continue;
      if (greater_div[x] == 1) {
         //cout << x << ' ' << rk[x] << endl;
         ans.push_back(rk[x]);
         nb[rk[x]]--;
      }
      else {
         if (nb[greater_div[x]] == 0)
            continue;
         ans.push_back(x);
         nb[greater_div[x]]--;
      }
      nb[x]--;
   }
   for (int i : ans)
      cout << i << ' ';
}