#include <bits/stdc++.h>

using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N, X; cin >> N >> X;
      int A[N], B[N];
      for (int i = 0; i < N; i++)
         cin >> A[i];
      for (int i = 0; i < N; i++)
         cin >> B[i];
      bool b = true;
      sort(A, A+N);
      sort(B, B+N);
      for (int i = 0; i < N; i++) {
         if (A[i]+B[N-1-i] > X)
            b = false;
      }
      if (b)
         cout << "yes" << endl;
      else
         cout << "no" << endl;
   }
}