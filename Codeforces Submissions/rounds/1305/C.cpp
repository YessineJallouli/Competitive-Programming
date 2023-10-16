#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

vector<ll> v;
int m;
ll sum = 0;
ll answer = 1;
void possible_sum(int pr)
{
   for (int i = max(pr+1, 0); i < v.size(); i++)
   {
      if (i > pr+1 && pr != -1)
         break;
      sum+= v[i];
      answer = (answer * sum)%m;
      possible_sum(i);
      sum-= v[i];
   }
}

int main()
{
   int n; cin >> n >>m; int num[n];
   for (int i= 0; i < n; i++)
      cin >> num[i];
   if (n > m) {
       cout << 0;  
       return 0;
   }
   sort(num, num+n);
   for (int i = n-1; i > 0; i--)
      v.push_back(num[i]-num[i-1]);
   possible_sum(-1);
   cout << (int) answer;
}