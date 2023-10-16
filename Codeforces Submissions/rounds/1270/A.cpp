/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define pb push_back

using namespace std;

int main()
{
    int t; cin >> t;
    for (int h = 0; h < t; h++)
    {
       int n, k1, k2; cin >> n >> k1 >> k2;
       vector<int> p1, p2;
       for (int b = 0; b < k1; b++)
       {
          int num; cin >> num;
          p1.push_back(num);
       }

       for (int b = 0; b < k2; b++)
       {
          int num; cin >> num;
          p2.push_back(num);
       }
       sort(p1.begin(), p1.end());
       sort(p2.begin(), p2.end());
       if (p1.back() > p2.back())
          cout << "YES" << endl;
       else
          cout << "NO" << endl;

    }
}