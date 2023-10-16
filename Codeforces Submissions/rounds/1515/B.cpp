#include <bits/stdc++.h>
using namespace std;

bool isS(int n) {
   int k = sqrt(n);
   if (k*k == n) {
      return true;
   }
   return false;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
      int l; cin >> l;
      if(isS(l/2) && l%2 == 0) {
         cout << "YES" << endl;
      }
      else if (isS(l/4) && l%4 == 0) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;


	}
}