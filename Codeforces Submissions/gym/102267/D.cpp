#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

enum State
{
    Normal,Blocked,Crossed
};

class Grid
{
protected:
    int n,m;
    struct NextState
    {
        int a, b;
        char c;
        NextState()=default;
        NextState(int a,int b,char c):a(a),b(b),c(c){}
    };
    std::vector<std::vector<State>> C;
    std::vector<std::vector<std::vector<NextState>>> adjacencyList;
public:
    Grid(int n,int m):n(n),m(m),C(n,std::vector<State>(m,State::Normal)),adjacencyList(n,std::vector<std::vector<NextState>>(m)){}
    Grid(const std::vector<std::string> &grid){}
    void mark(int a,int b,State s)
    {
        C[a][b]=s;
    }
    void buildAdjacencyList()
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if(i>0&& C[i][j]!=Blocked && C[i-1][j]!=Blocked)
                adjacencyList[i][j].emplace_back(i - 1, j,'U');
            if(j>0 && C[i][j]!= Blocked && C[i][j-1]!=Blocked)
                adjacencyList[i][j].emplace_back(i,j-1,'L');
            if(i<n-1 && C[i][j]!= Blocked && C[i+1][j]!=Blocked)
                adjacencyList[i][j].emplace_back(i+1,j,'D');
            if(j<m-1 && C[i][j]!= Blocked && C[i][j+1]!=Blocked)
                adjacencyList[i][j].emplace_back(i,j+1,'R');
        }
    }

    std::string optimalSteps(int a,int b)
    {
        std::queue<NextState> Q;
        std::vector<std::vector<NextState>> mapper(n,std::vector<NextState>(m));
        std::vector<std::vector<bool>> visited(n,std::vector<bool>(m));
        visited[a][b]=true;
        Q.emplace(a,b,'N');
        mapper[a][b]=NextState(a,b,'N');
        NextState destination;
        while(!Q.empty())
        {
            auto [u,v,c]=Q.front();
            if(C[u][v]==Crossed)
            {
                destination=Q.front();
                break;
            }
            Q.pop();
            for(auto [p,q,r]:adjacencyList[u][v]) if(!visited[p][q])
            {
                Q.emplace(p,q,r);
                mapper[p][q]=NextState(u,v,r);
                visited[p][q]=true;
            }
        }
        std::string S;
        while(destination.a != a || destination.b != b) {
            auto [u,v,c]=destination;
          S.push_back(c);
          destination=mapper[u][v];
          destination.c=mapper[destination.a][destination.b].c;
        }
        std::reverse(S.begin(),S.end());
        return S;
    }

    char encode(State s)
    {
        switch (s) {
            case Normal:
                return '.';
            case Blocked:
                return '#';
            case Crossed:
                return 'x';
        }
    }

    void print(std::ostream &H)
    {
        for(auto &R:C)
        {
            for(auto &s:R)
                H << encode(s);
            H << '\n';
        }
    }

};

class DefaultGrid :public Grid{
public:
    inline static constexpr int N=12,M=12;
    DefaultGrid(): Grid(N,M)
    {
        C[2][2]=Crossed;
        C[n-3][2]=Crossed;
        C[2][m-3]=Crossed;
        C[n-3][m-3]=Crossed;
        C[n-3][1]=Blocked;
        C[n-4][1]=Blocked;
        C[n-4][2]=Blocked;
        C[n-3][m-2]=Blocked;
        C[n-4][m-2]=Blocked;
        C[n-4][m-3]=Blocked;
        C[5][5]=Blocked;
        C[5][6]=Blocked;
        C[6][5]=Blocked;
        C[6][6]=Blocked;

    }
};

int main()
{
    int L;
    std::cin >> L;
    DefaultGrid G;
    G.buildAdjacencyList();
    //G.print(std::cout);
    while(L--)
    {
        int r,c;
        std::cin >> r >> c;
        r--;
        c--;
        auto S= G.optimalSteps(r,c);
        std::cout << S.length() << '\n' << S << '\n';
    }
}