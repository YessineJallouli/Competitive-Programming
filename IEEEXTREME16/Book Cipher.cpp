//100%
#include <iostream>
#include <vector>
#include <regex>
#include <bitset>

using vmatch=std::match_results<std::string_view::const_iterator>;
using rvmatch=std::match_results<std::string_view::const_reverse_iterator>;


void build(std::string &output,std::string_view input)
{
    std::regex beginDirective(R"(<(.+)>)");
    vmatch match;
    if(std::regex_search(input.begin(),input.end(),match,beginDirective))
    {
        auto S="<"+match[1].str()+"/>";
        std::reverse(S.begin(),S.end());
        std::regex endDirective(S);
        std::cout << match[1] << '\n';
        rvmatch revMatch;
        if(std::regex_search(input.rbegin(),input.rend(),revMatch,endDirective))
        {
        }

    }
}

std::string removeDirectives(const std::string& data)
{
    std::regex directive(R"(<[^>]+>)");
    auto result= std::regex_replace(data,directive,"");
    return result;
}

std::string removeDir(const std::string &data)
{
    std::string A;
    bool ignore=false;
    for(auto d:data)
    {
        if(d=='<')
            ignore= true;
        if(d=='>')
            ignore=false;
        else if(!ignore)
            A.push_back(d);
    }
    return A;
}

struct Encryption
{
    std::pair<int,int> A,B;
    auto operator<=>(const Encryption&O) const = default;
};


int main()
{
    std::string data,line;
    int p,n,R,C;
    std::cin >> p >> n >> R;
    std::cin.ignore();
    std::cin >> C;
    char mode;
    std::vector<std::string> S(p);
    std::cin >> mode;
    std::cin.ignore();
    for(auto &s:S)
        std::getline(std::cin,s);
    while(n--) {
        std::getline(std::cin, line);
        data += line;
    }

    std::map<char,Encryption> E;

    std::string output=removeDirectives(data);
    std::vector<std::vector<char>> G(R,std::vector<char>(C));
    for(int i=0,k=0;i<R;i++) for(int j=0;j<C;j++,k++)
        {
            G[i][j] = output[k];
            if(E.count(output[k]))
            {
                E[output[k]].A=std::min(E[output[k]].A,std::make_pair(i,j));
                E[output[k]].B=std::max(E[output[k]].B,std::make_pair(i,j));
            }
            else
                E[output[k]]={{i,j},{i,j}};
        }
    for(auto &R:G)
    {
        for(auto &r:R)
            std::cout << r;
        std::cout << '\n';
    }

    for(const auto &s:S)
    {
        std::vector<int> encryption;
        bool skip=false;
        for(auto c:s) {
            if (!E.count(c)) {
                skip = true;
                break;
            }
            else
            {
                auto &&[P,Q]=E[c];
                if(mode=='S') {
                    encryption.push_back(P.first+1);
                    encryption.push_back(P.second+1);
                }
                else
                {
                    encryption.push_back(Q.first+1);
                    encryption.push_back(Q.second+1);
                }
            }
        }
        if(skip)
            std::cout << 0 << '\n';
        else
        {
            for(int i=0;i<encryption.size()-1;i++)
                std::cout << encryption[i] << ',';
            std::cout << encryption.back() << '\n';
        }
    }
}
