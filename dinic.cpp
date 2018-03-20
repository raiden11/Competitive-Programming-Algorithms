
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

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

map<pair<ll,ll>, ll>ed;

struct edge
{
    ll v, w, flow, revid;
}edges[nn];
vi g[nn];
int n, depth[nn];

int level_graph(int s,int t)
{
    int i;
    for(i=0;i<=n;i++)
        depth[i]=-1;
    depth[s]=0;

    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto idx:g[node])
        {
            edge e = edges[idx];
            if(depth[e.v]==-1 and e.flow<e.w)
            {
                depth[e.v]=depth[node]+1;
                q.push(e.v);
            }
        }
    }
    return ((depth[t]<0)?0:1);
}

ll calc_flow(int s, ll flow, int t)
{

    if(s==t)
        return flow;
    for(auto idx:g[s])
    {
        edge &e = edges[idx];
        if(depth[e.v]==depth[s]+1 and e.flow<e.w)
        {
            //abhi tak min possible
            ll mn = min(flow, e.w-e.flow);

            // aage walo me se min possible flow
            ll tmp = calc_flow(e.v, mn, t);
            if(tmp>0)
            {
                e.flow+=tmp;
                edges[e.revid].flow-=tmp;
                return tmp;
            }
        }
    }
    return 0;
}

ll dinic(int s,int t)
{
    if(s==t)
        return -1;
    ll total_flow = 0, flow;
    while(level_graph(s, t))
    {
        while(flow = calc_flow(s,inf, t))
            total_flow+=flow;
    }
    return total_flow;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll x,y,w,m;
        cin>>n>>m;
        rep(i,m)
        {
            cin>>x>>y>>w;
            ed[mp(x,y)]+=w;
        }

        i=0;
        for(auto u:ed)
        {
            edges[i].v = u.ff.ss;
            edges[i].w = u.ss;
            g[u.ff.ff].pb(i);
            ed[mp(u.ff.ff, u.ff.ss)]=i;
            i++;

            edges[i].v=u.ff.ss;
            edges[i].w=u.ss;
            g[u.ff.ss].pb(i);
            ed[mp(u.ff.ss, u.ff.ff)]=i;
            i++;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

            }
        }

        ll ans = dinic(1, n);
        cout<<ans<<endl;
    }
    return 0;
}

