

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

// PROBLEM : SPOJ : COT

int vroot[nn],l[30*nn],r[30*nn];  //version root
int seg[30*nn],a[nn],nodes=0;
int depth[nn],par[nn],dp[nn][26] ,pos[nn];
vi g[nn];
vpii v;

void pre(int node,int p,int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=25;j++)
            dp[i][j]=-1;

    for(i=1;i<=n;i++)      // 1st ancestor of all nodes re set to their parent
        dp[i][0]=par[i];

    for(j=1;(1<<j)<=n;j++)
        for(i=1;i<=n;i++)
            if(dp[i][j-1]!=-1)
                dp[i][j] = dp[dp[i][j-1]][j-1];
}

int LCA(int p,int q)
{
    int i;
    if(depth[p]<depth[q])              //depth of p should be more ie p is more away from root
        swap(p,q);

    int log = log2(depth[p]);

    for(i=log;i>=0;i--)
        if(depth[p]-(1<<i)>=depth[q])
            p=dp[p][i];

    if(p==q)                      //returns here if q is ancestor of p
        return p;

    for(i=log;i>=0;i--)
        if(dp[p][i]!=-1&&dp[p][i]!=dp[q][i])   //finds ancestor when p!=q
            p=dp[p][i],q=dp[q][i];

    return dp[p][0];
}

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        seg[pos]=0;
        l[pos]=0;
        r[pos]=0;
        nodes = max(nodes,pos);
        return ;
    }
    int mid = (lo+hi)>>1;
    build(2*pos+1, lo, mid);
    build(2*pos+2, mid+1, hi);
    l[pos]=2*pos+1;
    r[pos]=2*pos+2;
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

void update(int pos, int prev, int pla, int x, int lo,int hi)
{
    if(lo==hi)
    {
        seg[pos]=x;
        l[pos]=0;
        r[pos]=0;
        return ;
    }
    int mid = (lo+hi)>>1;
    l[pos] = l[prev];
    r[pos] = r[prev];
    if(pla<=mid)
    {
        nodes++;
        l[pos]=nodes;
        update(nodes, l[prev], pla, x, lo, mid);
    }
    else
    {
        nodes++;
        r[pos]=nodes;
        update(nodes, r[prev], pla, x, mid+1, hi);
    }
    seg[pos] = seg[l[pos]]+seg[r[pos]];
}

int query(int a, int b , int c, int d, int lo, int hi, int k)
{

  //  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<seg[l[a]]<<" "<<seg[l[b]]<<" "<<seg[l[c]]<<" "<<seg[l[d]]<<endl;
  //  cout<<lo<<" "<<hi<<endl;
    if(lo==hi)
    {
        return lo;
    }

    int mid =(lo+hi)>>1;
    int val = seg[l[a]] + seg[l[b]] - seg[l[c]] - seg[l[d]];
    if(val >=k )
        return query(l[a], l[b], l[c], l[d], lo, mid, k);
    else
        return query(r[a], r[b],  r[c], r[d], mid+1, hi, k-val);
}

void dfs(int node ,int p,int d,int n)
{
    depth[node] = d;
    par[node] = p;

    nodes++;
    vroot[node]=nodes;
    update(vroot[node], vroot[p], pos[node], 1, 0, n-1);

    for(auto u:g[node])
        if(u!=p)
            dfs(u, node, d+1, n);
}


void solve()
{
    ll k,lca,p,i,j,n,q,x,y;

    cin>>n>>q;
    rep1(i,1,n)
    {
        cin>>a[i];
        v.pb(mp(a[i],i));
    }

    sort(all(v));
    for(i=0;i<n;i++)
    {
        pos[v[i].ss] = i;
    }

    rep(i,n-1)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    vroot[0]=0;

    build(0, 0, n-1);
    dfs(1, 0 , 0, n);
    pre(1,0,n);


    while(q--)
    {
        cin>>x>>y>>k;
        lca = LCA(x,y);
        p = par[lca];
        int idx = query(vroot[x], vroot[y], vroot[lca], vroot[p],0, n-1, k);
        cout<<v[idx].ff<<endl;
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



    }
    return 0;
}

