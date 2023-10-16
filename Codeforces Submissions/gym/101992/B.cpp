//
// Created by ramizouari on 06/10/2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>

int main()
{
    std::ifstream file("task.in");
    std::istream &in=file;
    int T;
    in >> T;
    while(T--)
    {
        int n;
        in >> n;
        std::map<int,int> mapper;
        std::set<int> S;
        std::vector<int> to_add(2*n+1),to_delete(2*n+1);
        int R=0,Q=0;
        for(int i=0;i<n;i++)
        {
            int a;
            in >> a;
            if(a>2*n)
            {
                to_delete[2*n]++;
                Q++;
                continue;
            }
            mapper[a]++;
            S.insert(a);
        }
        for(auto [_,m]:mapper) {
            R += std::max(m - 1, 0);
        }

        for(int i=1;i<=2*n;i++)
            to_add[i]=to_add[i-1]+(1-S.count(i));
        to_delete[2*n]+=S.count(2*n);
        for(int i=2*n-1;i>=0;i--)
            to_delete[i]=to_delete[i+1]+S.count(i);

        int P=to_add[2*n]+Q;
        int is_empty=1;
        for(int i=0;i<=2*n;i++)
            P=std::min(P,to_add[i]+to_delete[i+1]);
        for(int i=0;i<2*n;i++)
            if(P==to_add[i]+to_delete[i+1] && (to_delete[i+1]<n||to_add[i]>0))
            {
                is_empty = 0;
                break;
            }
        if(P==to_add[2*n]+Q)
            is_empty=0;

        std::cout << P+is_empty+R << '\n';
    }
}