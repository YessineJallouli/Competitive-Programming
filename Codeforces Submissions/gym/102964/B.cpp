//
// Created by ramizouari on 13/03/2021.
//

#include <vector>
#include <iostream>


int main()
{
    using namespace std;
    int n;
    cin >> n;
    vector<std::uint64_t> A(n);
    for(auto &a:A)
        cin >> a;
    std::uint64_t R=0;
    for(auto a:A)
        R^=a;
    cout << R;
}