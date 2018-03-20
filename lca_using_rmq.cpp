

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
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 212345;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
vi g[nn];
int depth[nn],par[nn],dp[nn][30];

void dfs(int node,int p,int lev)
{
    par[node] = p;
    depth[node] = lev;
    for(auto u:g[node])
    {
        if(u!=p)
        {
            dfs(u,node,lev+1);
        }
    }
}

//dp[i][j] is 2^j th ancestor of i

void pre(int node,int p,int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=25;j++)
            dp[i][j]=-1;

    for(i=1;i<=n;i++)      // 1st ancestor of all nodes re set to their parent
        dp[i][0]=par[i];

    for(j=1;(1<<j)<=n;j++)
        for(i=1;i<=n;i++)
            if(dp[i][j-1]!=-1)                     // will be -1 when ancestor 2^j would not exist
                dp[i][j] = dp[dp[i][j-1]][j-1];    //2^j th ancestor of i is 2^j-1 th ancestor of dp[i][j-1](2^j-1 th ancestor of i)
}

int LCA(int p,int q)
{
    int i;
    if(depth[p]<depth[q])              //depth of p should be more ie p is more away from root
        swap(p,q);

    int log = log2(depth[p]);

    // consider diff = level[p]-level[q] is the difference between the levels of p and q
    // then diff can be expressed as a sum of powers of 2
    // if we keep going to the ancestors of p according to the sequence of powers of 2, we would reach to the level of q

    for(i=log;i>=0;i--)
        if(depth[p]-(1<<i)>=depth[q])
            p=dp[p][i];

    if(p==q)                      //returns here if q is ancestor of p
        return p;

    // when p and q are at the same level, we keep moving upwards in the tree to their lca
    // here log can be bigger,so we can reach above their lca
    //to prevent this condition dp[p][i]!=dp[q][i] is used which ensures we do not move up if they are same
    //once log becomes less than the difference between their heights, condition becomes true and we start moving upwards till the lca is found
    for(i=log;i>=0;i--)
        if(dp[p][i]!=-1&&dp[p][i]!=dp[q][i])   //finds ancestor when p!=q
            p=dp[p][i],q=dp[q][i];

    return dp[p][0];
}

// to find xth parent of p
int parent(int p, int x)
{
    int log = log2(depth[p]);
    for(int i=log;i>=0;i--)
        if((x&(1<<i)))
            p = dp[p][i];
    return p;
}

int main()
{
    int i,j,n,tt,u,v;
    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,-1,0);
    pre(1,-1,n);

    cout<<LCA(5,3)<<endl;   //1
    cout<<LCA(17,10)<<endl; //2
    cout<<LCA(11,8)<<endl;  //3
    cout<<LCA(9,15)<<endl;  //4
    cout<<LCA(13,14)<<endl; //9
    cout<<LCA(5,17)<<endl;  //5
    cout<<LCA(17,5)<<endl;  //5
    cout<<LCA(12,1)<<endl;  //1
    return 0;
}

/*TESTCASE
17
1 2
1 3
3 6
3 7
3 8
6 11
6 12
2 4
2 5
4 9
4 10
5 16
16 17
10 15
9 13
9 14
*/
