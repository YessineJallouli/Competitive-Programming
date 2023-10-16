/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define pb push_back

using namespace std;

int main()
{
   string Ch; getline(cin, Ch);
   map<string, string> name;
   map<string, bool> here;
   while (Ch != "----------")
   {
      string a = "", b = "";
      int id = -1;
      for (int k = 0; k < Ch.size(); k++)
      {
         if (Ch[k] == ' ') { id = k+1; break;}
         a+= Ch[k];
      }
      for (int k = id; k < Ch.size(); k++)
      {
         if (Ch[k] == ' ') {id = k+1; break;}
         a += Ch[k];
      }
      for (int k = id+4; k < Ch.size(); k++)
         b+= Ch[k];
      name[a] = b;
      name[b] = a;
      getline(cin, Ch);
   }
   getline(cin, Ch);
   int nb = 0;
   while (Ch != "END")
   {
      if (Ch == "UNION")
         cout << nb << endl;
      string a = "", b = "";
      int id = -1;
      for (int k = 0; k < Ch.size(); k++)
      {
         if (Ch[k] == ' ')  {id = k+1; break;}
         a+= Ch[k];
      }
      bool bb = false;
      if (Ch[id] != 't') bb = true;
      for (int k = id; k < Ch.size(); k++)
      {
         if (Ch[k] == ' ') {id = k+1; break;}
         if (bb)
            b+= Ch[k];
      }
      for (int k = id; k < Ch.size(); k++)
         b+= Ch[k];
      if (a == "+")
      {
         here[b] = here[name[b]] = true;
         nb++;
      }
      else if (a == "-")
      {
         here[b] = here[name[b]] = false;
         nb--;
      }
      else if (a == "FIND")
      {
         if (here[b])
            cout << "FOUND" << endl;
         else
            cout << "404" << endl;
      }
      getline(cin, Ch);
   }
}