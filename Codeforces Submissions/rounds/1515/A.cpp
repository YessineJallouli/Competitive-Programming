#include <bits/stdc++.h>
using namespace std;


int main() {

	int T;
	cin >> T;
	while (T--) {
      int n; cin >> n;
      int x; cin >> x;
      int num[n];
      int sum = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         sum+= num[i];
      }
      if (sum == x) {
         cout << "NO" << endl;
      }
      else {
         cout << "YES" << endl;
         sort(num, num+n);
         sum = 0;
         int hidden = -1;
         for (int i = 0; i < n; i++) {
            sum+= num[i];
            if (sum == x) {
               sum-= num[i];
               hidden = num[i];
            }
            else {
               cout << num[i] << ' ';
            }
         }
         if (hidden != -1)
            cout << hidden;
         cout << endl;
      }
	}
}