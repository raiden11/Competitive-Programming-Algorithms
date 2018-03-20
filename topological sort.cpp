//topological sort
//directed graph

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
#include<stack>
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

// topological sort is the order of vertices such that for every edge u -> v, u always comes before v in the order
//logic:
//do dfs of every unvisited node
//after dfs is over.. ie when node become black..print node
//or push in a stack...pop later

stack<int>s;
vi ad[10000];
int vis[10000];
//max no of vertices, n is 10000

void dfs(int pos)
{
    int i;

    for(i=0;i<ad[pos].size();i++)
    {
        if(vis[ad[pos][i]]==0)
        {
            vis[ad[pos][i]]=1;
            dfs(ad[pos][i]);
            s.push(ad[pos][i]);     // when all neighbors of a node are explored then it is pushed into the stack
        }
    }
}

int main()
{
    int n,i,ans,j,m,x,y;
    scanf("%d%d",&n,&m);      // no of vertices and edges
    while(m--)
    {
        scanf("%d%d",&x,&y);  //edge directed from x to y
        ad[x].pb(y);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            s.push(i);
        }
    }
    cout<<endl;
    while(!s.empty())
    {
        x=s.top();
        s.pop();
        cout<<x<<" ";
    }
    return 0;
}
