//
// Created by ramizouari on 12/03/2021.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class graph
{
    std::uint64_t n;
    std::vector<std::vector<std::uint64_t>> children;
    std::vector<std::uint64_t> parent;
    std::uint64_t root;
    std::vector<std::uint64_t> height;
    std::vector<std::uint64_t> earning,manager_earning;
    std::vector<std::uint64_t> total_earning;
public:
    graph(std::uint64_t _n):n(_n),parent(_n),children(_n),earning(_n,0),manager_earning(_n,0),height(_n),total_earning(_n,0){}
    void set_parent(std::uint64_t i,std::uint64_t j)
    {
        if(j!=-1)
            children[j].push_back(i);
        else set_root(i);
        parent[i]=j;
    }
    void set_root(std::uint64_t r)
    {
        root=r;
    }
    void init_height()
    {
        std::queue<std::uint64_t> Q;
        Q.push(root);
        height[root]=1;
        while(!Q.empty())
        {
            auto w=Q.front();
            for(const auto &s:children[w])
            {
                Q.push(s);
                height[s]=height[w]+1;
            }
            Q.pop();
        }
    }

    void add_earning(std::uint64_t r,std::uint64_t amount,bool manager)
    {

        if(manager)
            manager_earning[r]+=amount;
        else    earning[r]+=amount;
    }

    void calculate_total_earning(std::uint64_t r)
    {
        total_earning[r]=manager_earning[r]*height[r];
        for(const auto &e:children[r]) {
            calculate_total_earning(e);
            total_earning[r]+=(height[r])*total_earning[e]/height[e];
            total_earning[e]-=(height[r])*total_earning[e]/height[e];
        }
    }

    void calculate_total_earning2(std::uint64_t r)
    {
        total_earning[r]=earning[r];
        for(const auto &e:children[r]) {
            calculate_total_earning2(e);
            total_earning[r]+=total_earning[e];
        }
    }

    void calculate_total_earning()
    {
        calculate_total_earning(root);
        for(std::uint64_t i=0;i<n;i++)
            earning[i]+=total_earning[i];
        calculate_total_earning2(root);

    }

    std::uint64_t get_total_earning(std::uint64_t r) const
    {
        return total_earning[r];
    }
    std::uint64_t get_earning(std::uint64_t r) const
    {
        return earning[r];
    }
};

int main()
{
    using namespace std;
    std::uint64_t n,m,q;
    std::queue<std::uint64_t>Q;
    cin >> n >> m >> q;
    vector<std::uint64_t> E(n);
    graph G(n);
    std::uint64_t e;
    for(std::uint64_t i=0;i<n;i++) {
        cin >> e;
        G.set_parent(i,e-1);
    }
    G.init_height();
    std::uint64_t t,u,v;
    for(std::uint64_t i=0;i<m;i++)
    {
        cin >> t >> u >> v;
        G.add_earning(u-1,v,t==2);
    }
    G.calculate_total_earning();
    for(std::uint64_t i=0;i<q;i++)
    {
        cin >> t >> u;
        Q.push(t==1?G.get_earning(u-1):G.get_total_earning(u-1));
    }
    while(!Q.empty())
    {
        cout << Q.front() << '\n';
        Q.pop();
    }
}