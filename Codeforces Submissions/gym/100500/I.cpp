#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+2;
ll T,n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++){
        string s="";
        vector<int> v(26,0);
        while (true){
            getline(cin,s);
            if(s=="*")
                break;
            //cin.ignore();
            for(char c:s){
                if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
                    if(c>='a') v[c-'a']++; else v[c-'A']++;
                }
            }
        }
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<26;++i) if (v[i] != 0) pq.push({v[i],i});
        //for(int i=0;i<26;++i) cout << v[i] << ' ';
        //cout << '\n';
        int ans=0;
        for(int i=0;i<5;++i){
            if (pq.empty())
                break;
            ans += pq.top().second;
            pq.pop();
        }
        string eff="Effective",in="Ineffective",x;
        if(ans>62) x=eff; else x=in;
        cout << "Case " << t << ": " << x << '\n';
    }

}