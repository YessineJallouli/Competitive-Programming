// Fool
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

ull po(int n)
{
   ull p = 1;
   for (int t = 0; t < n; t++)
      p*= 16;
   return p;
}

int main()
{
   string s; cin >> s;
   ull n;
   n = 11 * po(6) + (s[1] - '0') * po(5) + (s[2] - '0') * po(4) + (s[3] - '0') * po(3) + (s[4] - '0') * po(2) + (s[5] - '0') * po(1) + (s[6] - '0') * po(0);
   cout << (n%2);

}