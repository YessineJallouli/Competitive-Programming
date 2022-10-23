//100%
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>


using stringType=std::string;
constexpr int L=4;
struct DecisionNode
{
    stringType code;
    int successNode,failureNode;
    DecisionNode(std::string _code,int success,int failure):code(std::move(_code)),successNode(success),failureNode(failure){}
};

struct CountryGraph
{
    int root;
    std::map<int,DecisionNode> adjacencyList;
    std::map<int,int> parent;
    std::map<int,std::set<stringType>> languages;
    std::set<stringType> alphabet;
    void connect(int a,const stringType &code,int success,int failure)
    {
        adjacencyList.emplace(a,DecisionNode(code,success,failure));
        alphabet.emplace(code);
        parent.emplace(success,a);
        parent.emplace(failure,a);
    }

    void setLanguage(int a,const stringType&_language){
        languages.emplace(a,std::set<stringType>{_language});
    }

    int getRoot()
    {
        int s=parent.begin()->second;
        while(parent.count(s))
            s=parent[s];
        return root=s;
    }

    void buildPotentialLanguages()
    {
        getRoot();
        buildPotentialLanguages(root);
    }

    void buildPotentialLanguages(int id)
    {
        if(!adjacencyList.count(id))
            return;
        auto [_,s,f]=adjacencyList.at(id);
        buildPotentialLanguages(s);
        buildPotentialLanguages(f);
        languages[id]=languages[s];
        for(const auto &language:languages[f])
            languages[id].emplace(language);
    }

    void parse(const stringType &A)
    {
        std::set<stringType> isUsed;
        for(const auto& code:alphabet)
            if(A.find(code)!=stringType::npos)
                isUsed.emplace(code);
        std::queue<int> Q;
        Q.emplace(root);
        std::set<stringType> Z;
        while(!Q.empty())
        {
            auto id=Q.front();
            Q.pop();
            if(adjacencyList.count(id))
            {
                const auto &[code,success,failure]=adjacencyList.at(id);
                Q.emplace(success);
                if(!isUsed.count(code))
                    Q.emplace(failure);
            }
            else
                Z.insert(languages[id].begin(),languages[id].end());
        }
        for(auto&& z:Z)
            std::cout << z << ' ';
        std::cout << '\n';
    }
};

int main()
{

    int n,p;
    std::cin >> n >> p;
    CountryGraph G;
    for(int s=0;s<n;s++)
    {
        char nodeType;
        std::cin >> nodeType;
        int id;
        int success,failure;
        if(nodeType=='I')
        {
            std::string S;
            std::cin >> id >> S >> success >> failure;
            G.connect(id,S,success,failure);
        }
        else if(nodeType=='L')
        {
            std::string  S;
            std::cin >> id >> S;
            G.setLanguage(id,S);
        }
    }
    G.buildPotentialLanguages();
    std::cin.ignore();
    for(int s=0;s<p;s++)
    {
        std::string S;
        std::getline(std::cin,S);
        G.parse(S);
    }

}
