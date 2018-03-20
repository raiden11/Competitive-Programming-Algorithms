//mst
//spoj
//kruskal

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define inf 1000000000
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

//kruskal logic (greedy):
//arrange edges in non decreasing(increasing) order
// loop over edges
// if both end points in same dsu wala set, ignore
// else add edge to mst

ll par[10010],ran[10010];
struct ga
{
    ll a;
    ll b;
    ll w;
};
ga g[100010];
bool comp(ga abc,ga def)
{
    return (abc.w<def.w);
}
ll pfind(ll x)
{
    if(par[x]==x)
        return x;
    ll rem=pfind(par[x]);
    par[x]=rem;
    return rem;
}

void unite(ll x,ll y)
{
    ll r1=pfind(x);
    ll r2=pfind(y);
    if(ran[r1]>ran[r2])
        par[r2]=r1;
    else if(ran[r1]<ran[r2])
        par[r1]=r2;
    else
    {
        par[r2]=r1;
        ran[r1]++;
    }
}

int main()
{
    ll m,z,n,i,j,w,a,b,x,y,ans;
    ans=0;
    z=0;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<10010;i++)
    {
        par[i]=i;
        ran[i]=0;
    }
    for(i=0;i<m;i++)
        scanf("%lld%lld%lld",&g[i].a,&g[i].b,&g[i].w);
    sort(g,g+m,comp);
    for(i=0;i<m;i++)
    {
        ll x=pfind(g[i].a);
        ll y=pfind(g[i].b);
        if(x!=y)
        {
            z++;
            ans+=g[i].w;
            unite(g[i].a,g[i].b);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
