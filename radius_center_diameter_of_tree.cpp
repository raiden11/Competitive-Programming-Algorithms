
#include<bits/stdc++.h>
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

vi g[nn],v;
int lev[nn],deg[nn],maxlev=0,center,radius,diam,vis[nn];
queue<int> q;

void pre_dfs(int node,int par)
{
    vis[node]=1;
    if(deg[node]<=1)
        q.push(node);
    for(auto u:g[node])
        if(u!=par)
            pre_dfs(u,node);
}

void post_dfs(int node,int par)
{
    if(lev[node]==maxlev)
        v.pb(node);
    for(auto u:g[node])
        if(u!=par)
            post_dfs(u,node);
}

void rad(int node)
{
    maxlev=0;
    int root = node;
    while(!q.empty())
        q.pop();

    v.clear();
    pre_dfs(node,-1);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto u:g[node])
        {
            deg[u]--;
            if(deg[u]==1)
            {
                q.push(u);
                lev[u]=lev[node]+1;
                maxlev=max(maxlev,lev[u]);
            }
        }
    }

    post_dfs(root,-1);
    center = v[0];
    if(sz(v)>1)
        radius = maxlev+1, diam = 2*maxlev+1;
    else
        radius = maxlev, diam = 2*maxlev;
}



void solve()
{
    ll i,j,n,u,v;
    int maxlev=0,center,dia,radius;
    cin>>n;
    rep(i,n-1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            rad(i);
        // cout radius, diam, center
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

