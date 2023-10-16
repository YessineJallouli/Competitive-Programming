#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <map>


struct ConnectedComponent
{
    std::set<std::pair<int,int>> component;
    char color;
    std::partial_ordering operator<=>(const ConnectedComponent&O) const = default;
};

constexpr int convert(char c)
{
    if(c=='R')
        return 0;
    else if(c=='B')
        return 1;
    else if(c=='G')
        return 2;
    else if(c=='Y')
        return 3;
    return 4;
}

struct Grid
{
    std::vector<std::vector<char>> grid;
    int n,m;
    inline static constexpr int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    std::vector<ConnectedComponent> components;
    std::array<int,5> counter{};
public:

    std::partial_ordering operator<=>(const Grid& O) const
    {
        return components<=>O.components;
    }
    Grid(std::vector<std::vector<char>> && _grid):grid(std::move(_grid)),n(grid.size()),m(grid[0].size())
    {
        generate_components();
    }

    Grid(const std::vector<std::vector<char>> &_grid):grid(_grid)
    {
        generate_components();
    }

    void dfs(int i,int j,char c,std::vector<std::vector<bool>> &visited,ConnectedComponent &C)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(visited[i][j])
            return;
        if(grid[i][j]==c)
        {
            visited[i][j]=true;
            C.component.emplace(i, j);
            for (auto direction : directions) {
                auto newI=i+direction[0];
                auto newJ=j+direction[1];
                dfs(newI,newJ,c,visited,C);
            }
        }

    }

    void generate_components()
    {
        std::vector<std::vector<bool>> visited(n,std::vector<bool>(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
                if (!visited[i][j] && grid[i][j] != 'O') {
                    ConnectedComponent component;
                    component.color = grid[i][j];
                    dfs(i, j, grid[i][j], visited, component);
                    components.push_back(component);
                }
            counter[convert(grid[i][j])]++;
        }
    }

    std::vector<std::vector<char>> remove_component(const ConnectedComponent &component)
    {
        if(component.component.size()==1)
            return grid;
        std::vector<std::vector<char>> G=grid;
        for (int j = 0; j < m; j++)
        {
            int offset = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (component.component.count({i, j}))
                    offset++;
                else G[i + offset][j] = grid[i][j];
            }
            for(int i=0;i<offset;i++)
                G[i][j]='O';
        }
        int mOffset=0;
        for(int j=0;j<m;j++) {
            bool all_empty=true;
            for (int i = 0; i < n && all_empty; i++)
                all_empty=G[i][j]=='O';
            if(all_empty)
                mOffset++;
            else for(int i=0;i<n;i++)
                G[i][j-mOffset]=G[i][j];
        }
        for(int i=0;i<n;i++)
            G[i].resize(m-mOffset);

        int nOffset=0;
        for(int i=0;i<n;i++)
        {
            bool all_empty=true;
            for(int j=0;j<m-mOffset && all_empty;j++)
                all_empty = G[i][j]== 'O';
            if(all_empty)
                nOffset++;
            else G[i-nOffset]=G[i];
        }
        G.resize(n-nOffset);
        return G;
    }

};

int nb = 0;

bool solvable(Grid &G)
{
    static std::map<Grid,bool> mapper;
    for(int i=0;i<4;i++) if(G.counter[i]==1)
        return mapper[G]=false;
    if(mapper.count(G))
        return mapper[G];

    if(G.components.empty())
        return mapper[G]=true;
    for(auto& C:G.components)
    {

        Grid S(std::move(G.remove_component(C)));
        if(C.component.size() > 1 && solvable(S))
            return mapper[G]=true;
    }
    return mapper[G]=false;
}

constexpr int n=5,m=6;

int main()
{
    int T;
    std::cin >> T;
    for(int t=1;t<=T;t++)
    {
        std::vector<std::vector<char>> G(n,std::vector<char>(m));
        for(auto &R:G) for(auto &g:R)
            std::cin >> g;
        Grid grid(std::move(G));
        std::cout << "Case " << t << ": "  << (solvable(grid)?"Yes":"No") << '\n';
    }
}