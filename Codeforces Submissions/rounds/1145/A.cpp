#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int num[n];
    for (int t = 0; t < n; t++) cin >> num[t];
    bool b = true;
    int s = n;
    while (b)
    {
       for (int i = 0; i < n; i+= s)
       {
           bool k = true;
           for (int t = i; t < i+s-1; t++)
              if (num[t] > num[t+1])
                 k = false;
           if (k)
           {
              cout << s;
              return 0;
           }
       }
       s/= 2;
    }
}