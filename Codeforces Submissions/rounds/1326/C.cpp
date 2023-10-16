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
   #define PI 4*atan(1);

   using namespace std;

   int main()
   {
      ull n, k; cin >> n >> k;
      int num[n];
      ull nb = (((n + (n-k+1))* k) / 2);
      for (int i = 0; i < n; i++) cin >> num[i];

      vector<int> v;
      for (int i = 0; i < n; i++)
      {
         if (num[i] >= n-k+1)
            v.push_back(i+1);
      }
      ull all = 1;
      for (int i = 0; i < v.size()-1; i++)
         all = (all * (v[i+1] - v[i])) % 998244353;
      cout << (ull) nb << ' ' << (ull)all;
   }