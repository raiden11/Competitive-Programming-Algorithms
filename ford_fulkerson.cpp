//ford-fulkerson

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<set>
#include<stack>
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
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

int edge[1000][1000],par[1000],vis[1000],n;
int bfs(int a,int b)
{
    int i;
    queue<int>q;
    q.push(1);
    int x;
    vis[1]=1;
    while(!q.empty())           // normal bfs
    {
        x=q.front();
        if(x==b)
            break;
        q.pop();
        for(i=0;i<=n;i++)
        {
            if(edge[x][i]>0&&vis[i]==0)
            {
                q.push(i);
                par[i]=x;       //but here parent is also noted
                vis[i]=1;
            }
        }
    }

    i=b;
   // rep(i,n+1)
     //   cout<< par[i]<<" ";
    //cout<<endl;
    int flow=inf;
    while(par[i]!=0)
    {

        flow=min(flow,edge[par[i]][i]);   //min residual capacity
        i=par[i];
    }
    i=b;

    while(par[i]!=0)
    {
        edge[par[i]][i]-=flow;           // reducing residual
        edge[i][par[i]]+=flow;
        i=par[i];
    }

    return flow;

}

int main()
{

    freopen("ford_fulkerson.txt","r",stdin);
    int e,i,j,flow=0,ans=0,a,b,c;
    scanf("%d%d",&n,&e);

    while(e--)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge[a][b]=c;
    }

    for(i=0;i<10;i++)
    {
        memset(par,0,sizeof(par));
        memset(vis,0,sizeof(vis));
        flow=bfs(1,n);
        if(flow==inf)            // if no more augmenting path...bfs returns inf
            break;
        else
            ans+=flow;

    }
    rep(i,n+1)
    {
        rep(j,n+1)
            cout<<edge[i][j]<<" ";
        cout<<endl;
    }
    cout<<ans<<endl;           // max flow in graph
    return 0;
}
