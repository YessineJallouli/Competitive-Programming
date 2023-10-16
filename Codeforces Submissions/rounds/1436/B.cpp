#include <bits/stdc++.h>

using namespace std;

bool prime(int k) {
   if (k == 1)
      return false;
   for (int i = 2; i*i <= k; i++) {
      if (k%i == 0)
         return false;
   }
   return true;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      int k = 1;
      while (true) {
         if (prime(N+k-1) && !prime(k) && prime(k*(N-1) +1))
            break;
         k++;
      }
      int matrix[N][N];
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++)
            matrix[i][j] = 1;
      }
      for (int i = 0; i < N; i++)
         matrix[N-1][i] = matrix[i][N-1] = k;
      matrix[N-1][N-1] = 1;
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++)
            cout << matrix[i][j] << ' ';
         cout << endl;
      }
   }
}