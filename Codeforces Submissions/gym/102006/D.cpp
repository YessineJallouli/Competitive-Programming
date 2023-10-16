#include <iostream>
#include <vector>

using integer=std::int64_t;

struct Grid
{
    using couple=std::pair<int,int>;
    int n,m;
    std::vector<std::vector<std::vector<couple>>> adjacency_list;
    std::vector<std::vector<integer>> cost;
    std::vector<integer> scores;
    std::vector<std::vector<bool>> visited;
    explicit Grid(const std::vector<std::vector<char>>& grid,std::vector<integer> &&scores):
                n(grid.size()),m(grid[0].size()),adjacency_list(n+1,std::vector<std::vector<couple>>(m)),
                cost(n+1,std::vector<integer>(m)),visited(n+1,std::vector<bool>(m)),scores(std::move(scores))
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if (grid[i][j] == '.')
                adjacency_list[i][j].emplace_back(i + 1, j);
            else
            {
                adjacency_list[i][j].emplace_back(i + 1, j);
                if (j > 0)
                    adjacency_list[i][j].emplace_back(i + 1, j - 1);
                if (j < m-1)
                    adjacency_list[i][j].emplace_back(i + 1, j + 1);
            }
        }
    }


    integer max_score(int a,int b)
    {
        if(a==n)
        {
            visited[a][b]=true;
            cost[a][b]=scores[b];
            return cost[a][b];
        }
        if(visited[a][b])
            return cost[a][b];
        for(auto [p,q]:adjacency_list[a][b])
            cost[a][b]=std::max(cost[a][b], max_score(p,q));
        visited[a][b]=true;
        return cost[a][b];
    }

    integer maximum_total_score(const std::vector<integer> &B)
    {
        integer R=0;
        for(int j=0;j<m;j++)
            R+= max_score(0,j)*B[j];
        return R;
    }

};

int main()
{
    freopen("balls.in","r",stdin);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--)
    {
        int r,c;
        std::cin >> r >> c;
        std::vector<std::vector<char>> grid(r,std::vector<char>(c));
        std::vector<integer> B(c),S(c);
        for(auto &b:B)
            std::cin >> b;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++)
            std::cin >> grid[i][j];
        for(auto &s:S)
            std::cin >> s;
        Grid G(grid,std::move(S));
        std::cout << G.maximum_total_score(B) << '\n';
    }
}