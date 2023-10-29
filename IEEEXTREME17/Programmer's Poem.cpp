//100%
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

void split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }

    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

}

void toLower(string& data){
    for(char & i : data) i = (char) tolower(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    string tmp;
    cin >> n >> m;
    cin.ignore();
    vector<vector<string> > words(n);
    vector<string> sent(n);
    vector<vector<string> > txt(m);
    map<string,int> wset;
    for(int i=0;i<n;++i){
        getline(cin,sent[i]);
        toLower(sent[i]);
        if(sent[i].length()) split(sent[i],words[i],' ');
        for(const string& word : words[i]){
            wset[word] = i;
        }
    }
    getline(cin,tmp);
    for(int i=0;i<m;++i){
        getline(cin,tmp);
        toLower(tmp);
        split(tmp,txt[i],' ');
    }
    string ans = string(m,'X');
    map<int,char> used;
    map<int,int> cnt;
    for(int i=0;i<m;++i){
        if(wset.count(txt[i].back())) cnt[wset[txt[i].back()]]++;
    }
    char cur = 'A';
    for(int i=0;i<m;++i){
        if(!wset.count(txt[i].back())) continue;
        int w = wset[txt[i].back()];
        if(cnt[w]>1){
            if(!used.count(w)){
                if(cur=='X') cur++;
                used[w]=cur;
                cur++;
            }
            ans[i]=used[w];
        }
    }
    cout << ans;
}
