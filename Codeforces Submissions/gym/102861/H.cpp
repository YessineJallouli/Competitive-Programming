//
// Created by ramizouari on 14/10/2021.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const long long N = 51;
long long C[N][N];
long long A[N];
long long n,k,a,b;

ll dp(long long n, long long k) {
    if (k > n)
        return 0;
    if (C[n][k] != -1)
        return C[n][k];
    if (n == 0 || k == 0)
        return C[n][k] = 1;
    return C[n][k] = dp(n-1, k) + dp(n-1, k-1);
}

long long solve(long long w, long long k, long long l){
    if(k==0) return 1;
    if(w<=0 || l==0) return 0;
    long long p,val=0;
    for(p=0;p<l;p++){
        if(A[p]>w) break;
    }
    p--;
    val += dp(p,k);
    if(p>=k-1) val += solve(w-A[p],k-1,p);
    return val;
}

int main() {
    memset(C,-1,sizeof(C));
   cin >> n >> k;
   for(long long i=0;i<n;++i) cin >> A[i];
   sort(A,A+n);
   cin >> a >> b ;
   if(n>=k){
       cout << solve(b,k,n) - solve(a-1,k,n) << '\n';
   }
   else
       cout << 0;

}