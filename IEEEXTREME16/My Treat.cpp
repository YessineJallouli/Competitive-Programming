//100%
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int m;
        cin >> m;
        map<string,int> B,R;
        while(m--){
            string s;
            int n;
            cin >> s >> n;
            if(!R.count(s)) R[s]=0;
            B[s]+=n;
            for(int i=0;i<n;++i){
                cin >> s;
                R[s]++;
                if(!B.count(s)) B[s]=0;
            }
        }
        int nb=0,days=0;
        for(auto it:R){
            nb+=max(it.second-B[it.first],0);
            days=max(days,B[it.first]-it.second);

        }
        cout << nb << ' ' << days << '\n';
    }
}
