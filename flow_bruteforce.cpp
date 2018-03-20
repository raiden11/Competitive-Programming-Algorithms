

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define lf long double
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
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
ll pipe[50][50], f;

void augment(int node, int par[50],ll minedge)
{
    if(node==0)
    {
        f = minedge;
        return;
    }
    else
    {
        augment(par[node],par,min(minedge,pipe[par[node]][node]));
        pipe[par[node]][node]-=f;
        pipe[node][par[node]]+=f;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll val,flow=0,n,tt;
    char c1,c2;
    int u,v,i,j;

    cin>>n;
    rep(i,n)
    {
        cin>>c1>>c2;
        c1-='A';
        c2-='A';
        cin>>val;
        pipe[c1][c2]+=val;
        pipe[c2][c1]+=val;
    }

    /*
    rep(i,26)
    {
        rep(j,26)
            cout<<pipe[i][j]<<" ";
        cout<<endl;
    }
    */

    i = 1;
    while(1)
    {
        f=0;
        vi dist(50,inf);
        dist[0]=0;

        queue<int>q;
        q.push(0);

        int par[50];
        par[0]=-1;

        //cout<<"Path "<<i<<endl;
        i++;

        while(!q.empty())
        {
            u=q.front();
          //  cout<<u<<endl;
            q.pop();
            if(u==25)
                break;

            for(v=0;v<26;v++)
            {
                if(pipe[u][v]>0&&dist[v]==inf)
                {
                    dist[v]=dist[u]+1;
                    q.push(v);
                    par[v]=u;
                }
            }

        }
        f = inf;
        augment(25,par,inf);
        //cout<<"Flow "<<f<<endl;
        if(f==0)
            break;
        flow+=f;
    }

    cout<<flow<<endl;
    return 0;
}
