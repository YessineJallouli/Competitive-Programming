//
// Created by Rami on 20/05/2021.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
constexpr int max_age=101;
class management_graph
{
    std::vector<std::unordered_set<int>> adjacency_list,reverse_list;
    std::vector<int> inverse_mapper;
    int n;
    std::vector<int> ages,mapper;
public:
    management_graph(int _n,std::vector<int> &&_ages):ages(std::move(_ages)),n(_n),adjacency_list(_n),reverse_list(_n),
    mapper(_n),inverse_mapper(_n)
    {
        for(int i=0;i<n;i++) {
            mapper[i] = i;
            inverse_mapper[i]=i;
        }
    }
    void connect(int i,int j)
    {
        adjacency_list[i].insert(j);
        reverse_list[j].insert(i);
    }
    void disconnect(int i,int j)
    {
        adjacency_list[i].erase(j);
        reverse_list[j].erase(i);
    }

    void swap(int i,int j)
    {
        inverse_mapper[mapper[i]]=j;
        inverse_mapper[mapper[j]]=i;
        auto tmp=mapper[i];
        mapper[i]=mapper[j];
        mapper[j]=tmp;
    }

    int yongest_manager(int s) const
    {
        std::vector<bool> visited(n,false);
        std::queue<int> Q;
        Q.push(mapper[s]);
        visited[mapper[s]]=true;
        int Y=max_age;
        while(!Q.empty())
        {
            auto w=Q.front();
            if(inverse_mapper[w]!=s)
                Y=std::min(Y,ages[inverse_mapper[w]]);
            for(const auto &u:reverse_list[w])
            {
                if(visited[u])
                    continue;
                visited[u]=true;
                Q.push(u);
            }
            Q.pop();
        }
        return Y;
    }
};

int main()
{
    int N,M,I;
    std::cin >> N >> M >> I;
    std::vector<int> ages(N);
    for(auto &a:ages)
        std::cin >> a;
    management_graph G(N,std::move(ages));
    int a,b;
    for(int i=0;i<M;i++)
    {
        std::cin >> a >> b;
        G.connect(a-1,b-1);
    }
    char query;
    std::queue<int> R;
    for(int i=0;i<I;i++)
    {
        std::cin >> query;
        if(query=='T')
        {
            std::cin >> a >> b;
            G.swap(a-1,b-1);
        }
        else
        {
            std::cin >> a;
            R.push(G.yongest_manager(a-1));
        }
    }
    while(!R.empty())
    {
        auto s=R.front();
        if(s==max_age)
            std::cout << '*';
        else std::cout << s;
        std::cout << '\n';
        R.pop();
    }
}