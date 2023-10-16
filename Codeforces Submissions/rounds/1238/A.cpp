#include <iostream>
using namespace std;
int main()
{
   int t; cin>> t;
   while (t--) {
      long long a,b; cin>> a >> b;
      if (a-b == 1)
         cout << "NO" << endl;
      else
         cout << "YES" << endl;
   }
}