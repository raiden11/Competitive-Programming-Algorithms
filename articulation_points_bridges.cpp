
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

#define nn 123456

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

int a[1010],vis[1010],low_time[1010], vis_time[1010];
vi g[1010];
set<int> articulation_point;
int tme = 0,root_children = 0;
//    if(root_children > 1)
//        articulation_point.insert(root);

void dfs(int node,int p,int root){
    vis[node]=1;
    vis_time[node] = tme;
    low_time[node] = tme;
    tme++;
    for(auto u:g[node])
    {
        if(u!=p&&vis[u]==1)
            low_time[node] = min(low_time[node],low_time[u]);   // compare with vis_time of adjacent vertex not low time cos
                                                                // adjacent vertex might have other branches too that
        else if(u!=p&&vis[u]==0)
        {
            dfs(u, node, root);
            low_time[node] = min(low_time[node], low_time[u]);
            if(vis_time[node] < low_time[u])
                bridge[node][u] = 1,bridge[u][node] = 1;
            if(node!=root)
                if(vis_time[node] <= low_time[u])
                    articulation_point.insert(node);
            else
                root_children++;
        }
    }
}

int main()
{

    int i,j,n,m,ans,u,v;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int root = 1;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i,-1,root);
    }

    //for(i=1;i<=n;i++)
      //  cout<<i<<" "<<vis_time[i]<<" "<<low_time[i]<<endl;

    cout<<root_children<<endl;
    if(root_children > 1)
        articulation_point.insert(root);

    for(auto u: articulation_point)
        cout<<u<<endl;

    return 0;
}

