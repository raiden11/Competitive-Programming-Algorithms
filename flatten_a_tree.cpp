

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

vi ad[10000];
int ar[10000],vis[10000];
int idx;

// change this method to dfso
void dfs(int x)
{
    int j;
    ar[idx]=x;
    idx++;
    for(j=0;j<ad[x].size();j++)
    {
        if(vis[ad[x][j]]==0)
        {
            vis[ad[x][j]]=1;
            dfs(ad[x][j]);
        }
    }
}

int main()
{
    int i,j,n,a,b;
    int m;
    scanf("%d%d",&n,&m);
    idx=1;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        ad[a].pb(b);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        dfs(i);
    }
    for(i=1;i<=n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
