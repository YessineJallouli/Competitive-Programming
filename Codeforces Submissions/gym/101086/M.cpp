#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=101;

int main() {
    ios_base::sync_with_stdio(0);
    int t,n;
    cin >> t;
    while(t--){
        map<string,vector<pi> > mp;
        cin >> n;
        while(n--){
            int l,r,v;
            string s;
            cin >> s >> l >> r >> v;
            while(v--){
                cin >> s;
                mp[s].push_back({l,r});
            }
        }
        set<string> ans;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            bool flag=true;
            for(int i=1;i<it.second.size();++i){
                if(it.second[i].first<=it.second[i-1].second) flag=false;
            }
            if(!flag) ans.insert(it.first);
        }
        cout << ans.size() << '\n';
        for(auto s:ans) cout << s << '\n';

    }
}