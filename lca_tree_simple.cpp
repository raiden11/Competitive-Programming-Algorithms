
// lca in tree

#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rrep1(i,a,b) for(i=a;i>=b;i--)
#define fr freopen("x.txt","r",stdin)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

vector<int> v[1000];
int vis[1000],depth[1000],par[1000];

void dfs(int no,int deep)
{
    depth[no]=deep;
    int i;
    for(i=0;i<v[no].size();i++)
    {
        int p=v[no][i];
        if(vis[p]==0)
        {
            vis[p]=1;
            par[p]=no;
            dfs(p,deep+1);
        }
    }
    return ;
}

int find_lcs(int u,int v)
{
    if(depth[v]<depth[u])
        swap(u,v);
    if(u==v)
        return u;
    v=par[v];
    find_lcs(u,v);
}

int main()
{
    int i,j,n,ans,x,y;
    in(n)
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].pb(y);
    }
    par[1]=-1;
    dfs(1,0);
    int q;
    in(q)
    while(q--)
    {
        scanf("%d%d",&x,&y);
        cout<<find_lcs(x,y)<<endl;
    }
    return 0;
}
