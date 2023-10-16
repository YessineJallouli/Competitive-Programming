#include <bits/stdc++.h>
#define ll long long
using namespace std;

string inp;
char a1,a2;
int p,sz,sol;

int main()
{
    int n; cin >> n;
    ll esp = 0;
    ll maxia = 0;
    ll maxib = 0;
    ll mina = INT_MAX;
    ll minb = INT_MAX;
    for (int i = 0; i < n; i++) {
       ll a,b,c,d; cin >> a >> b >> c >> d;
       esp+= (c-a)*(d-b);
       maxia = max(maxia, c);
       maxib= max(maxib, d);
       mina = min(mina, a);
       minb = min(minb, b);
    }
    ll k = maxia-mina;
    ll k1 = maxib- minb;
    if (k== k1 && esp == k*k)
       cout << "YES";
    else
      cout << "NO";
}