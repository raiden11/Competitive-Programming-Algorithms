//strongly connected components
// DAG
//Kosaraju

#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define mod 1000000007
#define ll long long int
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

vi g[10000];
vi gt[10000];
int vis[10000];
set<pii>fin;
set<pii>::iterator it;
int tme;
void dfs(int no)
{
    int i=0;
    tme++;
    for(i=0;i<g[no].size();i++)
    {
        if(vis[g[no][i]]==0)
        {
            vis[g[no][i]]=1;
            dfs(g[no][i]);
        }
    }
    tme++;
    fin.insert(mp(tme,no));

}

int main()
{
    int n,m,i,j,ans,k,a,b;
    scanf("%d%d",&n,&m);   // n vertices, m edges  1 based indexing of vertices
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].pb(b);
        gt[b].pb(a);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(i);
        }
    }
    cout<<endl;
    for(it=fin.begin();it!=fin.end();it++)
    {
        pii tmp=*(it);
        cout<<tmp.ss<<" "<<tmp.ff<<endl;
    }
    return 0;
}
