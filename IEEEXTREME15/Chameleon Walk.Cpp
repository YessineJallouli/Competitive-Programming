#include <vector>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <queue>

using natural =long long;
class graph
{
    natural n;
    std::vector<std::unordered_map<natural,std::vector<std::pair<natural,char>>>> adjacency_list;
public:
    graph(natural _n):n(_n),adjacency_list(n){}
    void connect(natural a,natural b,natural d,char c)
    {
        adjacency_list[a][b].push_back({d,c});
        adjacency_list[b][a].push_back({d,c});
    }
    natural smallest_distance(char s,natural C,natural K)
    {
        using triplet=std::tuple<natural,natural,char>;
        std::priority_queue<triplet,std::vector<triplet>,std::greater<>> Q;
        Q.push({0,0,s});
        std::vector<std::vector<bool>> visited(n,std::vector<bool>(5,false));
        while(!Q.empty())
        {
            auto [d,w,c]=Q.top();
            Q.pop();
            if(w==n-1)
                return d;
            if(visited[w][c-'a'])
                continue;
            visited[w][c-'a']=true;
            for(auto [u,t]:adjacency_list[w]) for(auto [r,b]:t)
                Q.push({d+r+(b==c?0:C), u, b});
        }
        return K+1;
    }
};

int main()
{
    natural T;
    std::cin >> T;
    while(T--)
    {
        natural n,m;
        natural K;
        std::cin >> n >> m >> K;
        graph G(n);
        for(natural i=0;i<m;i++)
        {
            natural a,b;
            natural d;
            char c;
            std::cin >> a >> b >> d >> c;
            G.connect(a-1,b-1,d,c);
        }        if(G.smallest_distance('a',K+1,K)<=K)
        {
            std::cout << "relaxing" << '\n';
            continue;
        }
        else if(G.smallest_distance('a',1,K)>K)
        {
            std::cout << "impossible" << '\n';
            continue;
        }
        natural A=0,B=K,M,R=1;
        while(A<=B)
        {
            M=(A+B)/2;
            auto d=G.smallest_distance('a',M,K);
            if(d<=K)
            {
                A=M+1;
                R=M;
            }
            else B=M-1;
        }
        std::cout << R;
        std::cout << '\n';
    }
}
