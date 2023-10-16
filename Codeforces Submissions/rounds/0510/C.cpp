#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool ans = true;
vector<vector<int>> graph(26);
bool visite[26];
bool act[26];

deque<int> res;

void topsort(int node) {
   if (visite[node])
      return;
   visite[node] = true;
   act[node] = true;
   for (int ch : graph[node]) {
      if (act[ch])
         ans = false;
      topsort(ch);
   }
   act[node] = false;
   res.push_front(node);
}

int main() {
   SaveTime
   int n; cin >> n;
   string s[n];
   for (int i = 0; i < n; i++)
      cin >> s[i];
   for (int i = 0; i < n-1; i++) {
      int id = 0;
      while (s[i][id] == s[i+1][id]) {
         id++;
         if (s[i+1].size() == id) {
            if (s[i].size() > id)
               ans = false;
            break;
         }
         if (s[i].size() == id)
            break;
      }
      if (id == s[i+1].size() || id == s[i].size())
         continue;
      int c1 = s[i][id]-'a';
      int c2 = s[i+1][id]-'a';
      graph[c1].push_back(c2);
   }
   for (int i = 0; i < 26; i++) {
      topsort(i);
   }
   if (! ans) {
      cout << "Impossible";
      return 0;
   }
   for (int i : res)
      cout << char(i + 'a');
}