//
// Created by ramizouari on 13/03/2021.
//

#include <iostream>
#include <vector>


int main()
{
    using namespace std;
    std::uint64_t n;
    cin >> n;
    string S;
    S.reserve(n+1);
    for(int i=1;i<n;i++)
        S+='3';
    S.push_back('4');
    cout << S;
}