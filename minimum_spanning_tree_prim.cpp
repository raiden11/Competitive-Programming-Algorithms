//mst
//prim

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


pii edge[1000];      // contains minimum wala edge for vertices
set<pii>s;          //s contains heap elememts...work as priority queue
set<pii> mst;       // final edges in mst
vector<pii> ad[1000]; // adjacency list
int dis[1000];        // distance of ith vertex which is to be compared
int vis[1000];         //visited array for each vertex
int main()
{
    int i,j,k,l,m,n,ans,a,b,w;
    in(n)             // n is no of vertices
    in(m)             // m is no of edges
    s.insert(mp(0,1));
    dis[1]=0;         // distance of ith vertex which is to be compared
    for(i=2;i<=n;i++)
    {
        s.insert(mp(inf,i));     // all vertex distance is infinity except for 1 which is 0
        dis[i]=inf;
    }

    while(m--)
    {
        scanf("%d%d%d",&a,&b,&w);     //edge info
        ad[a].pb(mp(b,w));
        ad[b].pb(mp(a,w));
    }

    while(!s.empty())
    {
        pii now=*(s.begin());       // extracts min distance wala vertex
        mst.insert(edge[now.ss]);    //add its min wala edge to mst
        vis[now.ss]=1;
        //cout<<now.ff<<" "<<now.ss<<endl;
        s.erase(s.begin());                 //erase the least wala vertex
        for(i=0;i<ad[now.ss].size();i++)
        {
            pii nbr=ad[now.ss][i];
            if(vis[nbr.ff]==0&&nbr.ss<dis[nbr.ff])       // if distance of this edge is less than previous one, update
            {
                s.erase(s.find(mp(dis[nbr.ff],nbr.ff)));
                s.insert(mp(nbr.ss,nbr.ff));
                dis[nbr.ff]=nbr.ss;
                edge[nbr.ff]=mp(now.ss,nbr.ff);
            }
        }
        //cout<<"yo"<<endl;
    }
    mst.erase(mp(0,0));                                 //idk how it comes
    cout<<"\nthe edges in the mst are: \n" ;
    while(!mst.empty())
    {
        cout<<(*(mst.begin())).ff<<" "<<(*(mst.begin())).ss<<endl;
        mst.erase(mst.begin());
    }
    return 0;
}
