#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      deque<pair<int,int>> RI;
      deque<pair<int,int>> RP;
      deque<pair<int,int>> LI;
      deque<pair<int,int>> LP;
      int num[n];
      int ans[n+1];
      memset(ans, -1, sizeof ans);
      vector<tuple<int,char,int>> s;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      for (int i = 0; i < n; i++) {
         char c; cin >> c;
         s.push_back({num[i], c, i});
      }
      sort(s.begin(), s.end());
      for (int i = 0; i < n; i++) {
         char c = get<1>(s[i]);
         int id = get<2>(s[i]);
         int nu = get<0>(s[i]);
         if (c == 'R') {
            if (nu%2)
               RI.push_back({nu, id+1});
            else {
               RP.push_back({nu, id+1});
            }
         }
         else {
            if (nu%2) {
               LI.push_back({nu, id+1});
               if (RI.size() != 0) {
                  int h = RI.size()-1;
                  int z = LI.size()-1;
                  int x = LI[z].second;
                  int y = RI[h].second;
                  int nb = LI[z].first-RI[h].first;
                  ans[x] = nb/2;
                  ans[y] = nb/2;
                  RI.pop_back();
                  LI.pop_back();
               }
            }
            else {
               LP.push_back({nu, id+1});
               if (RP.size() != 0) {
                  int h = RP.size()-1;
                  int z = LP.size()-1;
                  int x = LP[z].second;
                  int y = RP[h].second;
                  int nb = LP[z].first-RP[h].first;
                  ans[x] = nb/2;
                  ans[y] = nb/2;
                  RP.pop_back();
                  LP.pop_back();
               }
            }
         }
      }
      sort(LI.begin(), LI.end());
      sort(RI.rbegin(), RI.rend());
      sort(LP.begin(), LP.end());
      sort(RP.rbegin(), RP.rend());
      int h = LI.size()-1;
      for (int i = 0; i < RI.size(); i++) {
         if (h < 0)
            break;
         int x = LI[h].second;
         int y = RI[i].second;
         int nb = LI[h].first-RI[i].first;
         if (nb < 0)
            continue;
         ans[x] = nb/2;
         ans[y] = nb/2;
         h--;
      }
      h = LP.size()-1;
      for (int i = 0; i < RP.size(); i++) {
         if (h < 0)
            break;
         int x = LP[h].second;
         int y = RP[i].second;
         int nb = LP[h].first-RP[i].first;
         if (nb < 0)
            continue;
         ans[x] = nb/2;
         ans[y] = nb/2;
         h--;
      }
      vector<pair<int,int>> RI1;
      vector<pair<int,int>> RP1;
      vector<pair<int,int>> LI1;
      vector<pair<int,int>> LP1;
      for (int i = 0; i < RI.size(); i++) {
         int x = RI[i].first;
         int y = RI[i].second;
         if (ans[y] == -1) {
            RI1.push_back({x,y});
         }
      }
      for (int i = 0; i < LI.size(); i++) {
         int x = LI[i].first;
         int y = LI[i].second;
         if (ans[y] == -1) {
            LI1.push_back({x,y});
         }
      }
      for (int i = 0; i < RP.size(); i++) {
         int x = RP[i].first;
         int y = RP[i].second;
         if (ans[y] == -1) {
            RP1.push_back({x,y});
         }
      }
      for (int i = 0; i < LP.size(); i++) {
         int x = LP[i].first;
         int y = LP[i].second;
         if (ans[y] == -1) {
            LP1.push_back({x,y});
         }
      }
      sort(RP1.rbegin(), RP1.rend());
      sort(RI1.rbegin(), RI1.rend());
      sort(LP1.begin(), LP1.end());
      sort(LI1.begin(), LI1.end());
      for (int i = 1; i < RP1.size(); i+=2) {
         int x = RP1[i].second;
         int y = RP1[i-1].second;
         int nb = m-RP1[i-1].first + (RP1[i-1].first-RP1[i].first)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      for (int i = 1; i < RI1.size(); i+=2) {
         int x = RI1[i].second;
         int y = RI1[i-1].second;
         int nb = m-RI1[i-1].first + (RI1[i-1].first-RI1[i].first)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      for (int i = 1; i < LP1.size(); i+=2) {
         int x = LP1[i].second;
         int y = LP1[i-1].second;
         int nb = LP1[i-1].first + (LP1[i].first - LP1[i-1].first)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      for (int i = 1; i < LI1.size(); i+=2) {
         int x = LI1[i].second;
         int y = LI1[i-1].second;
         int nb = LI1[i-1].first + (LI1[i].first - LI1[i-1].first)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      vector<pair<int,int>> RI2;
      vector<pair<int,int>> RP2;
      vector<pair<int,int>> LI2;
      vector<pair<int,int>> LP2;
      for (int i = 0; i < RI1.size(); i++) {
         int x = RI1[i].first;
         int y = RI1[i].second;
         if (ans[y] == -1) {
            RI2.push_back({x,y});
         }
      }
      for (int i = 0; i < LI1.size(); i++) {
         int x = LI1[i].first;
         int y = LI1[i].second;
         if (ans[y] == -1) {
            LI2.push_back({x,y});
         }
      }
      for (int i = 0; i < RP1.size(); i++) {
         int x = RP1[i].first;
         int y = RP1[i].second;
         if (ans[y] == -1) {
            RP2.push_back({x,y});
         }
      }
      for (int i = 0; i < LP1.size(); i++) {
         int x = LP1[i].first;
         int y = LP1[i].second;
         if (ans[y] == -1) {
            LP2.push_back({x,y});
         }
      }
      sort(RP2.rbegin(), RP2.rend());
      sort(RI2.rbegin(), RI2.rend());
      sort(LP2.begin(), LP2.end());
      sort(LI2.begin(), LI2.end());
      int nb1,nb2,x,y,nb,diff;
      if (RP2.size()*LP2.size()) {
         nb1 = LP2[0].first;
         nb2 = RP2[0].first;
         x = LP2[0].second;
         y = RP2[0].second;
         nb = max(nb1, m-nb2);
         nb1 = nb-nb1;
         diff = nb-(m-nb2);
         nb2 = m-diff;
         nb = nb+ (nb2-nb1)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      if (LI2.size()*RI2.size()) {
         nb1 = LI2[0].first;
         nb2 = RI2[0].first;
         x = LI2[0].second;
         y = RI2[0].second;
         nb = max(nb1, m-nb2);
         nb1 = nb-nb1;
         diff = nb-(m-nb2);
         nb2 = m-diff;
         nb = nb+ (nb2-nb1)/2;
         ans[x] = nb;
         ans[y] = nb;
      }
      for (int i = 1; i <= n; i++)
         cout << ans[i] << ' ';
      cout << endl;
   }
}