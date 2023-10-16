#include <iostream>

using namespace std;

int main()
{
   int T; cin >> T;
   while(T--) {
      int N; cin >> N;
      int ans = 0;
      while (N%6 == 0) {
         ans++;
         N/= 6;
      }
      while(N%3 == 0) {
         ans+=2;
         N/= 3;
      }
      if (N != 1)
         cout << -1 << '\n';
      else
         cout << ans << '\n';
   }
}