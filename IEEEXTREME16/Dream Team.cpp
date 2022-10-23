//100%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    ll B;
    cin >> B;
    vector<pp> P,G,S,F,C;
    ll p,g,s,f,c;
    string nm;
    ll in;
    cin >> p;
    for(int i=0;i<p;++i){
        cin >> nm >> in;
        nm+= " ";
        P.push_back({in,nm});
    }
    cin >> g;
    for(int i=0;i<g;++i){
        cin >> nm >> in;
        nm+= " ";
        G.push_back({in,nm});
    }
    cin >> s;
    for(int i=0;i<s;++i){
        cin >> nm >> in;
        nm+= " ";
        S.push_back({in,nm});
    }
    cin >> f;
    for(int i=0;i<f;++i){
        cin >> nm >> in;
        nm+= " ";
        F.push_back({in,nm});
    }
    cin >> c;
    for(int i=0;i<c;++i){
        cin >> nm >> in;
        nm+= " ";
        C.push_back({in,nm});
    }
    sort(P.begin(),P.end());
    sort(G.begin(),G.end());
    sort(S.begin(),S.end());
    sort(F.begin(),F.end());
    sort(C.begin(),C.end());
    ll sm=0,mx=0;
    vector<string> ans;
    for(auto it:C){
        sm+=it.first;
        if(sm>B){
            sm-=it.first;
            break;
        }
        for(auto it2:F){
            sm+=it2.first;
            if(sm>B){
                sm-=it2.first;
                break;
            }
            for(auto it3 : S){
                sm+=it3.first;
                if(sm>B){
                    sm-=it3.first;
                    break;
                }
                for(auto it4 :G){
                    sm+= it4.first;
                    if(sm>B){
                        sm-=it4.first;
                        break;
                    }
                    int j= upper_bound(P.begin(),P.end(),make_pair(B-sm,(string)"{"))-P.begin();
                    if(j){
                        j--;
                        while(j){
                            if(P[j-1].first==P[j].first) j--; else break;
                        }
                        sm+= P[j].first;
                        if(sm>mx){
                            mx=sm;
                            ans={P[j].second,it4.second,it3.second,it2.second,it.second};
                        }else if(sm==mx){
                            vector<string> v={P[j].second,it4.second,it3.second,it2.second,it.second};
                            ans=min(ans,v);
                        }

                        sm-= P[j].first;
                    }
                    sm-= it4.first;
                }
                sm-=it3.first;
            }
            sm-=it2.first;
        }
        sm-=it.first;
    }
    for(string ss:ans) cout << ss << '\n';

}
