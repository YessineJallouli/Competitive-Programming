#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>


class Graph
{
    std::map<std::string,int> mapper;
    std::map<int,std::string> inverseMapper;
    std::map<int,std::set<int>> adjacencyList;
public:

    int emplace(const std::string &A)
    {
        int a;
        if(!mapper.count(A)) {
            a = mapper[A] = mapper.size();
            inverseMapper[a]=A;
        }
        else
            a=mapper[A];
        return a;

    }

    std::pair<int,int> connect(const std::string &A,const std::string &B)
    {
        int a,b;
        if(!mapper.count(A)) {
            a = mapper[A] = mapper.size();
            inverseMapper[a]=A;
        }
        else
            a=mapper[A];
        if(!mapper.count(B)) {
            b = mapper[B] = mapper.size();
            inverseMapper[b]=B;
        }
        else
            b=mapper[B];
        adjacencyList[a].insert(b);
        return std::make_pair(a,b);
    }

    std::pair<int,int> connect(int a,const std::string &B)
    {
        int b;
        if(!mapper.count(B)) {
            b = mapper[B] = mapper.size();
            inverseMapper[b]=B;
        }
        else
            b=mapper[B];
        adjacencyList[a].insert(b);
        return std::make_pair(a,b);
    }

    std::vector<std::string> requirements(const std::vector<std::string> &C)
    {
        std::vector<bool> visited(mapper.size());
        for(auto &S:C)
        {
            auto s=mapper[S];
            if(visited[s])
                continue;
            visited[s]=true;
            std::queue<int> Q;
            Q.push(s);
            while(!Q.empty())
            {
                auto u=Q.front();
                Q.pop();
                for(auto &v:adjacencyList[u]) if(!visited[v])
                {
                    visited[v]=true;
                    Q.push(v);
                }
            }
        }
        std::vector<std::string> R;
        for(int i=0;i<mapper.size();i++) if(visited[i])
            R.push_back(inverseMapper[i]);
        return R;
    }
};

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int n,K;
        std::cin >> n >> K;
        Graph G;
        for(int i=0;i<n;i++)
        {
            std::string A;
            std::cin >> A;
            int m;
            std::cin >> m;
            int u=G.emplace(A);
            for(int j=0;j<m;j++)
            {
                std::string B;
                std::cin >> B;
                G.connect(u,B);
            }
        }
        std::vector<std::string> R;
        for(int i=0;i<K;i++)
        {
            R.emplace_back();
            std::cin >> R.back();
        }
        for(const auto& requirement:G.requirements(R))
            std::cout << requirement << '\n';
    }
}