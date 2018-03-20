
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define lf long double
#define in(x) scanf("%d",&x);
#define sz(x) ((int)x.size())
#define lld l64d
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rrep1(i,a,b) for(i=a;i>=b;i--)
#define stlfor(i,t) for(auto i =t.begin();i!=t.end();i++)
#define fr freopen("x.txt","r",stdin)
#define frc freopen("y.txt","w",stdout)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;
#define pset(n) fixed<<showpoint<<setprecision(n)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2000006;
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const L INF = numeric_limits<L>::max() / 4;
struct MinCostMaxFlow {
int N;
VVL cap, flow, cost;
VI found;
VL dist, pi, width;
VPII dad;
MinCostMaxFlow(int N) :
N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N,
VL(N)),
found(N), dist(N), pi(N), width(N), dad(N) {}
void AddEdge(int from, int to, L cap, L cost) {
this->cap[from][to] = cap;
this->cost[from][to] = cost;
}
void Relax(int s, int k, L cap, L cost, int dir)
{
L val = dist[s] + pi[s] - pi[k] + cost;
if (cap && val < dist[k]) {
dist[k] = val;
dad[k] = make_pair(s, dir);
width[k] = min(cap, width[s]);
}
}
L Dijkstra(int s, int t) {
fill(found.begin(), found.end(), false);
fill(dist.begin(), dist.end(), INF);
fill(width.begin(), width.end(), 0);
dist[s] = 0;
width[s] = INF;
while (s != -1) {
int best = -1;
found[s] = true;
for (int k = 0; k < N; k++) {
if (found[k]) continue;
Relax(s, k, cap[s][k] - flow[s][k],
cost[s][k], 1);
Relax(s, k, flow[k][s], -cost[k][s], -1);
if (best == -1 || dist[k] < dist[best])
best = k;
}
s = best;
}
for (int k = 0; k < N; k++)
pi[k] = min(pi[k] + dist[k], INF);
return width[t];
}
pair<L, L> GetMaxFlow(int s, int t) {
L totflow = 0, totcost = 0;
while (L amt = Dijkstra(s, t)) {
totflow += amt;
for (int x = t; x != s; x = dad[x].first) {
if (dad[x].second == 1) {
flow[dad[x].first][x] += amt;
totcost += amt * cost[dad[x].first][x];
} else {
flow[x][dad[x].first] -= amt;
totcost -= amt * cost[x][dad[x].first];
}
}
}
return make_pair(totflow, totcost);
}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    cin>>tt;
    while(tt--)
    {
        int cnt[30];
        cin>>n;
        rep1(i, 1, 26)
            cin>>cnt[i];

        MinCostMaxFlow ins(28+n*26);
        for(i=1;i<=26;i++)
            ins.AddEdge(0, i, cnt[i], 0);

        int k = 1;
        for(i=1;i<=26;i++)
        {
            for(j=27+(i-1)*n;j<(27 + i*n);j++)
            {
                if(((j-26)%n)%i == 0)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    ins.AddEdge(i, j, 1, k);
                    k++;
                }
            }
        }

        for(j=27;j<=26+n*26;j++)
            ins.AddEdge(j, n*26+27, 1, 0);

        pll a = ins.GetMaxFlow(0, 27+n*26);
        cout<<a.ff<<" "<<a.ss<<endl;

        cout<<endl<<endl;
        if(a.ff==n)
        {
            char ans[n+1];
            for(i=27;i<27+n*26;i++)
                if(ins.flow[i][27+n*26]==1)
                {
                    cout<<(i-27)%n<<" "<<((i-27)/n)<<endl;
                    ans[(i-27)%n] = (char)(97+(i-27)/n);
                }
            for(i=0;i<n;i++)
                cout<<ans[i];
            cout<<endl;
        }
        else
        {
            cout<<"#rekt"<<endl;
        }
    }
    return 0;
}

/*
3
3
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
6
3 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
10
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
