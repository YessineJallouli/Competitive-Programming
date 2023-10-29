//100%
//
// Created by ramizouari on 28/10/23.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <sstream>
#include <iomanip>
#include <cstdint>

using namespace std;
using integer=std::int64_t;

vector<int> v;
vector<integer> s;

set<int> happy;

void generate(int n) {
    if (n == 0) {
        int sum = 0;
        long long number = 0;
        for (int i : v) {
            number = number*10LL+i;
            sum+= i*i;
        }
        if (happy.count(sum))
            s.push_back(number);
        return;
    }
    if (v.empty()) {
        for (int i = 0; i <= 9; i++) {
            v.push_back(i);
            generate(n-1);
            v.pop_back();
        }
    }
    else {
        for (int i = v.back(); i <= 9; i++) {
            v.push_back(i);
            generate(n-1);
            v.pop_back();
        }
    }
}


integer count_smaller_permutations(integer L, integer N, const std::array<integer,25>& F)
{
    auto A_str=std::to_string(L);
    std::stringstream ss;
    ss << std::setw(A_str.size()) << std::setfill('0') << N;
    auto N_str=ss.str();
    std::array<integer,11> C{},C_cum{},D{},D_cum{};
    for(auto c:N_str) C[c - '0']++;
    for(int i=1;i<=10;i++)
        C_cum[i]=C[i-1]+C_cum[i-1];

    integer Q=1;
    for(auto c:C) Q*=F[c];
    integer R=0;
    for(int i=0; i < A_str.size(); i++)
    {
        auto H=C_cum[A_str[i] - '0'] ;
        H=H * F[A_str.size() - i-1];
        for(int j=0;j<10;j++)
            H/=F[C[j]];
        R+=H;
        D[A_str[i] - '0']++;
        for(int j=A_str[i] - '0'+1;j<=10;j++)
            C_cum[j]--;
        if(!C[A_str[i] - '0'])
            break;
        C[A_str[i] - '0']--;
    }
    return R;
}


using real=double;

std::int64_t count_happy(integer L,const std::array<integer,25>& F)
{
    integer R=0;
    for(auto h:s)
    {
        if(h>=L)
            break;
        R+=count_smaller_permutations(L,h,F);
    }
    return R;
}

int main()
{
    std::array<integer,25> F{};
    F[0]=1;
    for(int i=1;i<25;i++)
        F[i]=F[i-1]*i;
    for (int N = 1; N <= 2000; N++) {
        int n = N;
        int nb = 0;
        while (n != 1) {
            string ch = to_string(n);
            int k = 0;
            for (char c : ch) {
                int h = c-'0';
                k+= h*h;
            }
            n = k;
            nb++;
            if (nb > 40)
                break;
        }
        if (n == 1)
            happy.insert(N);
    }
    generate(16);
    integer L,R;
    std::cin >> L >> R;
    std::cout << count_happy(R+1,F)-count_happy(L,F) << '\n';

}

