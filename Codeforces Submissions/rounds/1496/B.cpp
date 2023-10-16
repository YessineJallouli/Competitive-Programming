#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


int main()
{
    using namespace std;
    int t;
    cin >> t;
    std::queue<int> Q;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> A(n);
        for(auto &a:A)
            cin >> a;
        std::sort(A.begin(),A.end());
        int distinct=0;
        int occ=1;
        int a=0;
        for(int i=1;i<n;i++) {
            if (A[i] != A[i - 1]) {
                occ = 1;
                distinct++;
            } else
                occ++;
        }
        for(int i=0;i<n;i++)
        {
            if(A[i]!=a)
                break;
            else a++;
        }        int b = A.back();
        if(occ==1)
            distinct++;
      if(distinct==A.back()+1 && A.front()==0)
            Q.push(distinct+k);
            
        else if(k>0) {
            int s=(a+b+1)/2;
            auto search=std::find(A.begin(),A.end(),s);
            if(search==A.end())
                distinct++;
          Q.push(distinct);
      }
        else Q.push(distinct);
    }
    while(!Q.empty())
    {
        cout << Q.front() << '\n';
        Q.pop();
    }
    return false;
}