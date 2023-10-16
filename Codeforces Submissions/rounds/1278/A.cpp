#include <bits/stdc++.h>

using namespace std;

int main()
{
   int k;
   cin >> k;
   cin.ignore();
   for (int t = 0; t < k; t++)
   {
       string ch, ch1, ch2 = "";
       getline(cin, ch);
       getline(cin, ch1);
       if (ch1.length() < ch.length())
           cout << "NO" << endl;
       else
       {
           sort(ch.begin(), ch.end());
           bool verifie = false;
           for (int h = 0; h < ch.length(); h++)
               ch2 += ch1[h];
           string ch3 = ch2;
           sort(ch3.begin(), ch3.end());
           if (ch3 == ch)
               verifie = true;
           for (int h = ch.length(); h < ch1.length(); h++)
           {
               ch2.erase(0,1);
               ch2 += ch1[h];
               string ch3 = ch2;
               sort(ch3.begin(), ch3.end());
               if (ch3 == ch)
                   verifie = true;
           }
           if (verifie)
               cout << "YES" << '\n';
           else
               cout << "NO" << '\n';
       }
   }
}