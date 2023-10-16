//
// Created by ramizouari on 13/03/2021.
//

#include <vector>
#include <iostream>
using natural=std::uint64_t;
constexpr natural M=1e9+7;
int main()
{
    using namespace std;
    int n;
    cin >> n;
    vector<vector<natural>> S(n+2,std::vector<natural>(n+2,0));
    vector<natural> F(n+2);
    S[0][0]=1;
    F[0]=1;
    for(int i=1;i<=n+1;i++){

        for(int j=1;j<=n+1;j++)
        {
            S[i][j] = (j * S[i - 1][j])%M + S[i - 1][j - 1];
            S[i][j]%=M;
        }
        F[i]=(i*F[i-1])%M;
    }
    natural R=0;
    natural r=2;
    for(int k=0;k<n+1;k++)
    {
        natural s=((F[k]*S[n+1][k+1])%M)*r;
        s%=M;
        R += (n+k)%2==0?s:M-s;
        R%=M;
        r=(2*r)%M;
    }
    cout << R;
}