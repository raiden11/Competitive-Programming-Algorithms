//detect cycle in undirected graph
//dsu
//can also be done by dfs


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

//logic:
//for all edges in random order..do dsu on its end points
//if end points belong to same set,cycle found
//else unite them

int par[1000];
int rnk[1000];
pii edge[100000];

int find_par(int x)
{
    if(par[x]==x)
        return x;
    par[x]=find_par(par[x]);
    return par[x];
}

void unite(int x,int y)
{
    int p1=find_par(x);
    int p2=find_par(y);
    if(rnk[p1]>rnk[p2])
        par[p2]=p1;
    else if(rnk[p2]>rnk[p1])
        par[p1]=p2;
    else
    {
        par[p1]=p2;
        rnk[p2]++;
    }
}

int main()
{
    int n,m,i,j,x,y,ans;
    in(n)
    in(m)
    rep(i,n+1)
    {
        rnk[i]=0;
        par[i]=i;
    }
    int cyc=0;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        edge[i]=mp(x,y);
    }
    for(i=0;i<m;i++)
    {
        if(find_par(edge[i].ff)==find_par(edge[i].ss))
        {
            cyc=1;
            break;
        }
        else
            unite(edge[i].ff,edge[i].ss);
    }
    cout<<cyc<<endl;
    return 0;
}
