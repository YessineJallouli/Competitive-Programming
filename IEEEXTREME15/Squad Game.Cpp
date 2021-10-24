#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>

using real=long double;
struct point
{
    real x,y;
    bool operator==(point O) const{
        return x==O.x && y==O.y;
    }
    bool operator!=(point O) const
    {
        return !(*this==O);
    }
    real metric(point O) const
    {
        return std::sqrt(std::pow(x*O.x,2)+std::pow(y*O.y,2));
    }
    real det(point O) const{
        return std::abs(x*O.y-y*O.x);
    }

    point operator-(point A) const
    {
        return {x-A.x,y-A.y};
    }
};
using triangle=std::tuple<int,int,int>;

int main()
{
    int n;
    std::cin >> n;
    std::deque<std::pair<point,int>> P1(n),P2(n),P3(n);
    std::vector<triangle> A;
    int i=1;
    for(auto &[x,y]:P1) {
        std::cin >> x.x >> x.y;
        y=i++;
    }
    i=1;
    for(auto &[x,y]:P2) {
        std::cin >> x.x >> x.y;
        y=i++;
    }
    i=1;
    for(auto &[x,y]:P3) {
        std::cin >> x.x >> x.y;
        y=i++;
    }
    for(int i=0;i<n;i++)
    {
        std::vector<std::pair<std::pair<point,int>,std::pair<point,int>>> V;
        for(auto p:P2) for(auto q:P3)
            V.emplace_back(p,q);
        auto u=P1.front();
        P1.pop_front();
        std::sort(V.begin(),V.end(),[u](auto x,auto y){return (x.first.first-u.first).det(x.second.first-u.first)<(y.first.first-u.first).det(y.second.first-u.first);});
        auto [v,w]=V.front();
        A.emplace_back(u.second,v.second,w.second);
        decltype(P1) Q2,Q3;
        for(auto p:P2)
            if(p.second!=v.second)
                Q2.emplace_back(p);
        for(auto p:P3)
            if(p.second!=w.second)
                Q3.emplace_back(p);
        P2=std::move(Q2);
        P3=std::move(Q3);
    }
    for(auto [a,b,c]:A)
        std::cout << a <<' '<<b<<' ' << c << '\n';
}
