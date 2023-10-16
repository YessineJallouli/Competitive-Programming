#include <iostream>
#include <set>
#include <random>
#include <algorithm>
#include <map>


int main()
{
    std::random_device dev;
    std::mt19937_64 g(4);
    std::string alphabet;
    for(char c='a';c<='z';c++)
        alphabet.push_back(c);
    constexpr int L=10, queries=6;
    std::vector<std::string> S(queries);
    std::vector<std::set<int>> Q(alphabet.size());
    while(true)
    {
        for(int i=0;i<queries;i++) {
            std::shuffle(alphabet.begin(), alphabet.end(), g);
            for (int j = 0; j < L; j++)
                Q[alphabet[j]-'a'].insert(i);
            S[i]=alphabet.substr(0,L);
        }
        std::set<std::set<int>> Z;
        for(auto &x:Q)
            Z.insert(x);
        if(Z.size()==alphabet.size())
            break;
        else for(auto &q:Q)
            q.clear();
    }
    //for(auto s:S)
        //std::cout << s << '\n';
    std::vector<std::pair<std::set<int>,char>> A;
    for(int i=0;i<alphabet.size();i++)
        A.emplace_back(Q[i],'a'+i);
    std::sort(A.begin(),A.end(),[](const auto &A1,const auto &A2){return A1.first.size() > A2.first.size();});
    std::vector<std::set<int>> positions(queries);
    for(int i=0;i<queries;i++)
    {

        std::cout << "? " << S[i] << std::endl;
        auto &P=positions[i];
        int n;
        std::cin >> n;
        while(n--)
        {
            int r;
            std::cin >> r;
            P.insert(r-1);
        }
    }
    std::vector<std::set<int>> alphabet_indexes(alphabet.size());
    std::map<int,char> answer;
    for(auto &I:alphabet_indexes) for(int i=0;i<=1e4;i++)
        I.insert(i);
    for(auto &[E,c]:A)
    {
        for(auto k:E)
        {
            std::vector<int> exclude;
            for(auto &i:alphabet_indexes[c-'a']) if(!positions[k].contains(i))
                exclude.push_back(i);
            for(auto e:exclude)
                alphabet_indexes[c-'a'].erase(e);
        }
        for(auto k:E) for(auto a:alphabet_indexes[c-'a'])
            positions[k].erase(a);
    }
    for(int i=0;i<alphabet.size();i++) for(auto k:alphabet_indexes[i])
        answer[k]='a'+i;
    std::string R;
    for(auto [_,c]:answer)
        R.push_back(c);
    std::cout << "! " << R << std::endl;
}