#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
vector<vector<int>> graph(N);

bool visite[N];
bool act[N];
deque<int> res;
bool cycle = false;

void topsort(int node) {
    if (visite[node])
        return;
    visite[node] = true;
    act[node] = true;
    for (int ch : graph[node]) {
        if (act[ch])
            cycle = true;
        topsort(ch);
    }
    act[node] = false;
    res.push_front(node);
}


long double angle(int u, int v)
{
    auto theta= std::atan2(v,u)*180/std::numbers::pi;
    if(theta<0)
        return theta+360;
    return theta;
}

long double angle(int x1,int y1, int x2, int y2)
{
    return angle(x2-x1,y2-y1);
}

long double convert(double s)
{
    double theta= s*180/std::numbers::pi;
    if(theta<0)
        return theta+360;
    return theta;
}

long double eps = 1e-7;

bool canSee(tuple<int,int,int,int> &t1, tuple<int,int,int,int>& t2,vector<complex<double>> &rots) {
    auto &&[x1,y1,a1,r1]=t1;
    auto &&[x2,y2,a2,r2]=t2;
    complex<double> z(x2-x1,y2-y1);
    if(a1-r1 >= 0)
        z/=rots[a1-r1];
    else
        z/=rots[360+a1-r1];
    auto theta=convert(std::arg(z));
    return theta<=2*r1+eps;
}

int main() {
    std::vector<complex<double>> Rots(360);
    for(int i=0;i<360;i++)
        Rots[i]=std::polar<double>(1,i*std::numbers::pi/180);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        visite[i] = act[i] = false;

    vector<tuple<int,int,int,int>> v;
    for (int i = 0; i < n; i++) {
        int x,y,a,r; cin >> x >> y >> a >> r;
        v.emplace_back(x,y,a,r);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (canSee(v[i], v[j],Rots)) {
                //cout << i << ' ' << j << '\n';
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        topsort(i);
    }
    if (cycle) {
        cout << -1;
    }
    else {
        for (int i : res) {
            cout << i+1<< ' ';
        }
    }
}