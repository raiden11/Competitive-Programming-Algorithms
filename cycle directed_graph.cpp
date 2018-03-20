// detect cycle in a directed graph
//dfs

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
// do dfs on every unvisited vertex... white,gray,black notations as usual
// if during dfs of a vertex... a vertex x comes and it is in gray set,then graph has a cycle

vi ad[1000];
int vis[1000],cyc;                  //global variable cyc
set<int> white,gray,black;
void dfs(int no)
{
    int i;
    for(i=0;i<ad[no].size();i++)
    {
        if(vis[ad[no][i]]==1&&gray.find(ad[no][i])!=gray.end())     // if node is visited and in gray set,cycle found
            cyc=1;
        else if(vis[ad[no][i]]==0)
        {
            vis[ad[no][i]]=1;
            white.erase(ad[no][i]);
            gray.insert(ad[no][i]);
            dfs(ad[no][i]);
            gray.erase(ad[no][i]);
            black.insert(ad[no][i]);
        }
    }
}

int main()
{
    int i,j,k,n,m,x,y,a,b;
    in(n)
    in(m)
    cyc=0;
    for(i=1;i<=n;i++)
        white.insert(i);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        ad[a].pb(b);
    }

    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;                //do dfs on every unvisited node
            white.erase(i);
            gray.insert(i);
            dfs(i);
            gray.erase(i);
            black.insert(i);
        }
    }
    cout<<cyc<<endl;
    return 0;
}
