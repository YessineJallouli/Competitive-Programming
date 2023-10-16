#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

char s[9][9];

void b(int a1, int b1)
{
   if (s[a1][b1] == '1')
      s[a1][b1] = '2';
   else
      s[a1][b1] = '1';
}

int main()
{
   int T; cin >> T;
   while (T--) {
      for (int i = 0; i < 9; i++) {
         string S; cin >> S;
         for (int j = 0; j < 9; j++)
            s[i][j] = S[j];
      }

      b(0,0); b(1, 3); b(2, 6); b(3, 1); b(4, 4); b(5, 7); b(6, 2); b(7, 5); b(8, 8);

      for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++)
            cout << s[i][j];
         cout << endl;
      }
   }
}