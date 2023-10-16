#include <iostream>
#include <stack>
#include <vector>


int main()
{
    int n;
    std::cin >> n;
    std::string S;
    std::cin >> S;
    std::stack<int> Q;
    std::vector<int> supervisor(n);
    int a=0;
    int id;
    while(a<S.length())
    {
        if(S[a]=='(')
        {
            a++;
            int b=a;
            while(std::isdigit(S[b]))
                b++;
            id=std::stoi(S.substr(a,b-a));
            supervisor[id-1]=Q.top();
            continue;
        }
        if(S[a]==')')
        {
            a++;
            Q.pop();
            continue;
        }
        int b=a;
        while(std::isdigit(S[b]))
            b++;
        id=std::stoi(S.substr(a,b-a));
        a=b;
        Q.push(id);
    }
    for(auto s:supervisor)
        std::cout << s << ' ';
};