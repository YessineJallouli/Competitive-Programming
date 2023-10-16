#include <iostream>
#include <vector>

using real = long double;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n,a,b;
    std::cin >> n >> a >> b;
    std::vector<real> E(n+1,0),S(n+1,0);
    real K=(a==0)?static_cast<real>(b+1)/static_cast<real>(b):1;
    std::cout.precision(8);
    for(int i=1;i<=n;i++) {
        E[i] = K * (S[std::max(i - (a == 0 ? 1 : a), 0)] - S[std::max(i - b - 1, 0)]) / (b - a + 1)+K;
        S[i]=E[i]+S[i-1];
    }

    std::cout << E[n] << '\n';
    return 0;
}