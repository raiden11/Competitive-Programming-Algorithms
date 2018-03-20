//HLD
//QTREE

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
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 10010;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

vector<pii > g[nn];
int chno =0, ptr=0,n;   //globally declared n
int chhead[nn], posinbase[nn], chainno[nn], chidx[nn];
int depth[nn], subsize[nn], par[nn], dp[nn][30];
int seg[4*nn],base[nn];
pair<int,pair<int,int> >edge[nn];

void dfs(int node,int p,int lev)
{
    par[node] = p;
    subsize[node]++;
    depth[node] = lev;
    dp[node][0]=p;

    for(auto u:g[node])
    {
        if(u.ff!=p)
        {
            dfs(u.ff,node,lev+1);
            subsize[node]+=subsize[u.ff];
        }
    }
}

int LCA(int p,int q)
{
    int i;
    if(depth[p]<depth[q])
        swap(p,q);

    int log = log2(depth[p]);

    for(i=log;i>=0;i--)
        if(depth[p]-(1<<i)>=depth[q])
            p=dp[p][i];

    if(p==q)
        return p;

    for(i=log;i>=0;i--)
        if(dp[p][i]!=-1&&dp[p][i]!=dp[q][i])   //finds ancestor when p!=q
            p=dp[p][i],q=dp[q][i];

    return dp[p][0];
}

void hld(int node,int p,int cost)
{
    int idx;
    if(chhead[chno]==-1)
        chhead[chno]=node;

    posinbase[node]=ptr;   // position of this node in base array
    chidx[node]=chno;     // stores chain no for every node
    base[ptr] = cost;     // stores wt of parent to node edge in base array

    ptr++;
    int sch = -1;   // special child
    int sch_cnt=0,schcost=0;     // node count of special child subtree

    for(auto u:g[node])
    {
        if(u.ff!=p)
        {
            if(sch==-1 || subsize[u.ff]>sch_cnt)
            {
                sch = u.ff;
                sch_cnt = subsize[u.ff];
                schcost = u.ss;
            }
        }
    }

    if(sch!=-1)
        hld(sch,node,schcost);

    for(auto u:g[node])
    {
        if(u.ff!=p&&sch!=u.ff)
        {
            chno++;
            hld(u.ff,node,u.ss);
        }
    }
}

void build(int lo,int hi,int pos)
{
    if(hi==lo)
    {
        seg[pos]=base[lo];
        return;
    }
    int c = (pos<<1)+1;
    int mid = (lo+hi)>>1;
    build(lo,mid,c);
    build(mid+1,hi,c+1);
    seg[pos]=(seg[c]>seg[c+1])?seg[c]:seg[c+1];
}

void update(int lo,int hi,int pos,int place,int val)
{
    if(lo==hi)
    {
        seg[pos] = val;
        return ;
    }
    int mid=(lo+hi)>>1;
    int c = (pos<<1)+1;

    if(place<=mid)
        update(lo, mid, c, place, val);
    else
        update(mid+1, hi, c+1, place, val);
    seg[pos]=(seg[c]>seg[c+1])?seg[c]:seg[c+1];
}

int treequery(int lo,int hi,int pos,int x,int y)
{
    if(x>y)
        return 0;
    if(hi<x||y<lo)
        return 0;
    else if(x<=lo&&hi<=y)
        return seg[pos];
    int mid=(lo+hi)>>1;
    int c=(pos<<1)+1;
    return max(treequery(lo,mid,c,x,y),treequery(mid+1,hi,c+1,x,y));
}

int query_up(int u,int v)
{
    int uchain,vchain=chidx[v];
    int ans=-1,x,y;
    if(u==v)
        return 0;
    while(true)
    {
        uchain=chidx[u];
        if(uchain==vchain)
        {
            if(u==v)
                return ans;
            x=min(posinbase[u],posinbase[v]);
            y=max(posinbase[u],posinbase[v]);
            return max(ans,treequery(0,n-1,0,x+1,y));
        }
        else
        {
            ans=max(ans,treequery(0,n-1,0,posinbase[chhead[chidx[u]]],posinbase[u]));
            u=par[chhead[chidx[u]]];
        }
    }
}

int query(int u,int v)
{
    int lca = LCA(u,v);
    return max(query_up(u,lca),query_up(v,lca));
}

int main()
{
    std::ios::sync_with_stdio(false);

    int i,j,tt,u,v,w,idx,c;
    cin>>tt;
    while(tt--)
    {
        cin>>n;

        ptr=0,chno=0;

        //clear all first
        for(i=0;i<=n+1;i++)
        {
            g[i].clear();
            par[i]=0;
            subsize[i]=0;
            chainno[i]=0;
            chidx[i]=0;
            base[i]=0;
            posinbase[i]=0;
            depth[i]=0;
            chhead[i]=-1;
        }

        set0(seg);
        set0(base);

        for(i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
            edge[i]=mp(u,mp(v,w));
        }

        memset(dp,-1,sizeof(dp));

        chno=0;
        dfs(1,-1,0);
        hld(1,-1,-1);
        build(0,n-1,0);

        for(j=1;(1<<j)<=n;j++)
            for(i=1;i<=n;i++)
                if(dp[i][j-1]!=-1)
                    dp[i][j] = dp[dp[i][j-1]][j-1];

        char str[10];

        while(true)
        {
            cin>>str;

            if(str[0]=='D')
                break;
            else if(str[0]=='Q')
            {
                cin>>u>>v;
                cout<<query(u,v);
            	cout<<'\n';
            }
            else
            {
                cin>>idx>>c;   //update edge
             //   cout<<"yo "<<u<<endl;
                edge[u].ss.ss=c;
                u=edge[idx].ff;
                v=edge[idx].ss.ff;
                if(par[v]==u)
                    swap(u,v);
                update(0,n-1,0,posinbase[u],c);
            }
        }
        cout<<'\n';
    }
    return 0;
}

/*
12
11
1 2 3
1 3 5
3 9 9
2 4 11
2 5 1
3 8 10
4 11 1
5 6 4
5 7 14
6 10 3
*/
