//program to centroid decompose a given tree
// iiit threads quora


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
const int nn = 100006;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

int depth[nn], subs[nn], par[nn][26], cp[nn], root, val[nn];
si g[nn];

int predfs(int node,int p,int lev)
{
    depth[node]=lev;
    int sub = 1;
    par[node][0]=p;
    for(auto u:g[node])
        if(u!=p)
            sub += predfs(u,node,lev+1);

    subs[node]=sub;
    return sub;
}

void prelca(int n)
{
    int i,j;
    for(j=1;(1<<j)<=n;j++)
        for(i=1;i<=n;i++)
            if(par[i][j-1]!=-1)                     // will be -1 when ancestor 2^j would not exist
                par[i][j] = par[par[i][j-1]][j-1];    //2^j th ancestor of i is 2^j-1 th ancestor of dp[i][j-1](2^j-1 th ancestor of i)

}

int LCA(int p,int q)
{
    int i;
    if(depth[p]<depth[q])              //depth of p should be more ie p is more away from root
        swap(p,q);

    int log = log2(depth[p]);

    for(i=log;i>=0;i--)
        if(depth[p]-(1<<i)>=depth[q])
            p=par[p][i];

    if(p==q)                      //returns here if q is ancestor of p
        return p;

    for(i=log;i>=0;i--)
        if(par[p][i]!=-1&&par[p][i]!=par[q][i])   //finds ancestor when p!=q
            p=par[p][i],q=par[q][i];

    return par[p][0];
}

int dist(int p, int q)
{
    return (depth[p] + depth[q] -2*depth[LCA(p,q)]);
}

int dfs1(int node,int p)
{
    subs[node]=1;
    for(auto u:g[node])
        if(u!=p)
            subs[node] += dfs1(u,node);
    return subs[node];
}

int centroid_find(int node,int p, int lim)
{
    for(auto u:g[node])
        if(u!=p and subs[u]>lim)
            return centroid_find(u, node, lim);
    return node;
}

void centroid_decompose(int node,int p)
{
    dfs1(node,-1);
    int centroid = centroid_find(node, -1,subs[node]/2);
    if(p==-1)
        root=centroid;
    cp[centroid]=p;
    for(auto u:g[centroid])
    {
        g[u].erase(centroid);
        centroid_decompose(u,centroid);
    }
}


void update(int node, int anc)
{
    while(anc!=-1)
    {
        val[anc] = min(val[anc], dist(anc,node));
        anc = cp[anc];
    }
}

int query(int node ,int anc)
{
    int mn = 1e9;
    while(anc!=-1)
    {
        mn = min(mn, val[anc] + dist(anc,node));
        anc = cp[anc];
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t,i,j,n,m,x,y;
    cin>>n>>m;

    memset(par,-1,sizeof(par));
    rep(i,n-1)
    {
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }

    for(i=0;i<=n;i++)
        val[i]=1e9;

    predfs(1,-1,0);
    prelca(n);

    centroid_decompose(1,-1);

    update(1,1);
    while(m--)
    {
        cin>>t>>x;
        if(t==2)
            cout<<query(x,x)<<endl;
        else
            update(x,x);
    }

}
