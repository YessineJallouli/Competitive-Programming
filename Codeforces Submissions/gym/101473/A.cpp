#include <iostream>
#include <vector>

int main() {
    int S[3];
    for(int i=0;i<3;i++)
        std::cin>> S[i];
    char O;
    std::vector<int> T[2];
    for(int i=0;i<3;i++)
        T[S[i]].push_back(i);
    if(T[0].size()==1)
        O=static_cast<char>(T[0].back()+'A');
    else if(T[1].size()==1)
        O=static_cast<char>(T[1].back()+'A');
    else
        O='*';
    std::cout << O<< '\n';
    return 0;
}