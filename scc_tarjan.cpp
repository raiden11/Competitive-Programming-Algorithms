
#include<bits/stdc++.h>

using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
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
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
int SCC = 0, tme = 0;
int a[123456],vis[123456],low_time[123456],vis_time[123456];
vi g[123456];
stack<int> nodes;
mii mm;

void dfs(int node)
{
    int i,v;
    vis_time[node] = tme;
    low_time[node] = tme;
    tme++;
    vis[node] = 1;

    nodes.push(node);

    for(auto u:g[node])
    {
        if(vis[u]==0&&mm[u]==0)
            dfs(u);
        if(vis[u]==1&&mm[u]==0)
            low_time[node] = min(low_time[node], low_time[u]);
    }

    if(vis_time[node] == low_time[node])
    {
        printf("SSC : %d\n", SCC++);
        while(true)
        {
            v = nodes.top();
            cout<<v<<" ";
            mm[v]=1;
            nodes.pop();
            if(v == node)
                break;
        }
        cout<<endl;
    }
}

int main()
{
    int i,j,n,m,u,v,ans;
    int t;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].pb(v);
    }

    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<vis_time[i]<<" ";
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<low_time[i]<<" ";
    }
    return 0;
}

